#!/bin/bash
GREEN='\e[1;32m'
PURPLE='\e[1;35m'
RED='\e[1;31m'
WHITE='\e[1;37m'
RESET='\033[0m'

# Add in logic to check if the time_to_die is at start or end of eating with time_to_eat

# Function to test error cases. Checks that something is written to either stdout or stderr.
# Will also report segmentation fault and report which arguments caused it.

run_err() 
{
	local test_desc=$1
	local runtime=5
	shift
	> .julestestfile
	> .julestestout
	> .julesstderr

	( ./philo "$@" 1> .julestestout 2> .julesstderr ) &
	PID=$!
	SECONDS=0
	while ps -p $PID > /dev/null; do
		if [ $SECONDS -gt $runtime ]; then
			kill $PID
			echo -n "❌"
			echo -e "$test_desc: Program timed out. Possible infinite loop\n" >> philo_trace
			return 1
		fi
		sleep 1
	done
	wait $PID
	exit_code=$?
	if [ $exit_code -eq 139 ]; then
		echo -n "❌"
		echo -e "$test_desc: Segmentation Fault\n" >> philo_trace
	elif [ ! -s .julestestout ] && [ ! -s .julesstderr ]; then
		echo -n "❌"
		echo -e "$test_desc: No error message found\n" >> philo_trace
	else
		echo -n "✅"
	fi
}

# Function to test one philosopher. Will check to make sure they die and at the correct time.
# Test also implicitly tests that 4 arguments are valid as this is not tested explicitly elsewhere.

run_one()
{
	local test_desc=$1
	local min=$3
	local max=$((min + 10))
	local runtime=20
	local first_ts
	shift
	> .julestestout
	> .julesone
	( ./philo $@ 1> .julesone 2> /dev/null ) &
	PID=$!
	SECONDS=0
	while ps -p $PID > /dev/null; do
		if [ $SECONDS -gt $runtime ]; then
			kill $PID
			echo -n "❌" 
			echo -e "$test_desc: Program timed out. Possible infinite loop\n" >> philo_trace
			return 1
		fi
		sleep 1
	done
	wait $PID
	exit_code=$?
	if [ $exit_code -eq 139 ]; then
		echo -n "❌"
		echo -e "$test_desc: Segmentation Fault\n" >> philo_trace
		return 1
	fi
	first_ts=$(head -n 1 .julesone | awk '{print $1}')
	time=$(tail -n 1 .julesone | awk '{print $1}')
	if [[ ! $first_ts =~ ^[0-9]+$ ]] || [[ ! $time =~ ^[0-9]+$ ]] || [[ ! $3 =~ ^[0-9]+$ ]]; then
		echo -n "❌"
		echo -e "$test_desc: Timestamp error: Non numerical\n\tSimulation start: $first_ts Death: $time\n" >> philo_trace
		return 1
	elif [[ ! $min =~ ^[0-9]+$ ]]; then
		echo -n "❌"
		echo -e "$test_desc: Input error: Non numerical\n\tTime to die: $min\n" >> philo_trace
		return 1
	fi
	if ((time - first_ts >= min - 1)) && ((time - first_ts <= max)); then
		tail -n 1 .julesone | sed 's/[0-9]\+ //' > .julestestout
		if diff .julestestout .julestestfile > /dev/null; then
			echo -n "✅"
		else
			echo -n "❌"
			echo -e "$test_desc: Philosopher did not die\n" >> philo_trace
		fi
	else
		echo -n "❌"
		echo -e "$test_desc: Philosopher did not die on time\nSimulation start: $first_ts Death: $time\n" >> philo_trace
	fi
}

# Function to test valid input. Checks timestamps of philo 1 to make sure actions are correctly timed.

run_full()
{
	local test_desc=$1
	local philo=$2
	local time_eat=$4
	local time_sleep=$5
	local eat=$6
	local forks=$(( eat * philo * 2))
	local tolerance=1
	local runtime=20
	local pickups
	local meals
	shift
	> .julestestout
	> .julesphilo1log
	( ./philo $@ 1> .julestestout 2> /dev/null ) &
	PID=$!
	SECONDS=0
	while ps -p $PID > /dev/null; do
		if [ $SECONDS -gt $runtime ]; then
			kill $PID
			echo -n "❌"
			echo -e "$test_desc: Program timed out. Possible infinite loop\n" >> philo_trace
			return 1
		fi
		sleep 1
	done
	wait $PID
	exit_code=$?
	if [ $exit_code -eq 139 ]; then
		echo -n "❌"
		echo -e "$test_desc: Segmentation Fault\n" >> philo_trace
		return 1
	fi
	awk '$2 == "1"' .julestestout > .julesphilo1log
	read eat_time1 sleep_time1 think_time1 < <(awk '
	$4 == "eating" && !eat_time1 {
		eat_time1 = $1
	}  
	eat_time1 && $4 == "sleeping" && !sleep_time1 {
		sleep_time1 = $1
	}  
	sleep_time1 && $4 == "thinking" {
		think_time1 = $1
		print eat_time1, sleep_time1, think_time1
		exit
	}
	' .julesphilo1log)
	awk '$2 == "2"' .julestestout > .julesphilo2log
	read eat_time2 sleep_time2 think_time2 < <(awk '
	$4 == "eating" && !eat_time2 {
		eat_time2 = $1
	}  
	eat_time2 && $4 == "sleeping" && !sleep_time2 {
		sleep_time2 = $1
	}  
	sleep_time2 && $4 == "thinking" {
		think_time2 = $1
		print eat_time2, sleep_time2, think_time2
		exit
	}
	' .julesphilo2log)
	if [[ ! $eat_time1 =~ ^[0-9]+$ ]] || [[ ! $eat_time2 =~ ^[0-9]+$ ]] || [[ ! $sleep_time1 =~ ^[0-9]+$ ]] || [[ ! $sleep_time2 =~ ^[0-9]+$ ]] || [[ ! $think_time1 =~ ^[0-9]+$ ]] || [[ ! $think_time2 =~ ^[0-9]+$ ]]; then
		echo -n "❌"
		echo -e "$test_desc: Timestamp error: Non numerical\n\tPhilo 1 eating timestamp: $eat_time1 Philo 1 sleep timestamp: $sleep_time1 Philo 1 think timestamp: $think_time1 Philo 2 eating timestamp: $eat_time2 Philo 2 sleep timestamp: $sleep_time2 Philo 2 think timestamp: $think_time2\n" >> philo_trace
	elif [[ ! $philo =~ ^[0-9]+$ ]] || [[ ! $time_eat =~ ^[0-9]+$ ]] || [[ ! $time_sleep =~ ^[0-9]+$ ]] || [[ ! $eat =~ ^[0-9]+$ ]]; then
		echo -n "❌"
		echo -e "$test_desc: Input error: Non numerical\n\tPhilo no: $philo Time to eat: $time_eat Time to sleep: $time_sleep No of times to eat: $eat\n" >> philo_trace
	elif [[ ! $forks =~ ^[0-9]+$ ]]; then
		echo -n "❌"
		echo -e "$test_desc: Calculation error: Non numerical\n\tNo of forks collected: $forks\n" >> philo_trace
	elif grep -q " died" .julestestout; then
		result=$(grep -q " died" .julestestout)
		echo -n "❌"
		echo -e "$test_desc: Philosopher died\n\t$result\n" >> philo_trace
	elif [ "$(grep "is eating" .julestestout | wc -l)" -lt $((eat * philo)) ]; then
		result=$(grep -c "is eating" .julestestout)
		echo -n "❌"
		echo -e "$test_desc: Philosophers did not eat enough\n\tExpected: $((eat * philo)) Actual: $result\n" >> philo_trace
	elif [ "$(grep "has taken a fork" .julestestout | wc -l)" -lt $forks ]; then
		result=$(grep -c "has taken a fork" .julestestout)
		echo -n "❌"
		echo -e "$test_desc: Philosophers did not take enough forks\n\tExpected: $forks Actual: $result\n" >> philo_trace
	elif [ $(( $(grep "has taken a fork" .julestestout | wc -l) / 2 )) -gt $(grep "eating" .julestestout | wc -l) ]; then
		count=$(grep -c "has taken a fork" .julestestout)
		result=$((count / 2 ))
		expected=$(grep -c "eating" .julestestout )
		if ((expected - result == 1)); then
			echo -n $'\u26A0\uFE0F'
			echo -e "$test_desc: Warning! If philosophers continue eating after eating the required number of times then this test may flag a false positive. Check implementation." >> philo_trace
		else
			echo -n "❌"
			echo -e "$test_desc: Philosophers took too many forks\n\tExpected: $expected Actual $result\n" >> philo_trace
		fi
	elif [ "$(grep "is sleeping" .julestestout | wc -l)" -lt $((eat - 1)) ]; then
		result=$(grep -c "is sleeping" .julestestout)
		expected=$((eat - 1))
		echo -n "❌"
		echo -e "$test_desc: Philosophers did not sleep enough\n\tExpected: $expected Actual: $result\n" >> philo_trace
	elif ((sleep_time1 - eat_time1 < time_eat || sleep_time1 - eat_time1 > time_eat + tolerance)); then
		result=$(sleep_time1 - eat_time1)
		echo -n "❌"
		echo -e "$test_desc: Philosophers did not eat for the correct time\n\tExpected: $time_eat Actual: $result\n" >> philo_trace
	elif ((think_time1 - sleep_time1 < time_sleep || think_time1 - sleep_time1 > time_sleep + tolerance)); then
		result=$(think_time1 - sleep_time1)
		echo -n "❌"
		echo -e "$test_desc: Philosophers did not sleep for the correct time\nExpected: $time_sleep Actual: $result\n" >> philo_trace
	elif ((sleep_time2 - eat_time2 < time_eat || sleep_time2 - eat_time2 > time_eat + tolerance)); then
		result=$(sleep_time2 - eat_time2)
		echo -n "❌"
		echo -e "$test_desc: Philosophers did not eat for the correct time\n\tExpected: $time_eat Actual: $result\n" >> philo_trace
	elif ((think_time2 - sleep_time2 < time_sleep || think_time2 - sleep_time2 > time_sleep + tolerance)); then
		result=$(think_time2 - sleep_time2)
		echo -n "❌"
		echo -e "$test_desc: Philosophers did not sleep for the correct time\nExpected: $time_sleep Actual: $result\n" >> philo_trace
	else
		echo -n "✅"
	fi
}

# Function to test cases where philosophers should die. Will check the log ends with death message.
# Also tests whether philosophers died at appropriate times.

run_death()
{
	local test_desc=$1
	local philo=$2
	local min=$3
	local max=$((min + 10))
	local time_eat=$4
	local time_sleep=$5
	local eat=$6
	local runtime=20
	shift
	> .julestestout
	> .julesphilo1log
	( ./philo $@ 1> .julestestout 2> /dev/null ) &
	PID=$!
	SECONDS=0
	while ps -p $PID > /dev/null; do
		if [ $SECONDS -gt $runtime ]; then
			kill $PID
			echo -n "❌"
			echo -e "$test_desc: Program timed out. Possible infinite loop\n" >> philo_trace
			return 1
		fi
		sleep 1
	done
	wait $PID
	exit_code=$?
	if [ $exit_code -eq 139 ]; then
		echo -n "❌"
		echo -e "$test_desc: Segmentation Fault\n" >> philo_trace
		return 1
	fi
	time=$(tail -n 1 .julestestout | awk '{print $1}')
	dead_id=$(awk '$3 == "died" {id = $2} END {print id}' .julestestout)
	awk -v id="$dead_id" '$2 == id' .julestestout > .julesdeathlog
	last_meal=$(awk '$4 == "eating" {time = $1} END {print time}' .julesdeathlog)
	: "${last_meal:=0}"
	awk '$2 == "1"' .julestestout > .julesphilo1log
	variance=$((time - last_meal))
	if [[ ! $time =~ ^[0-9]+$ ]] || [[ ! $last_meal =~ ^[0-9]+$ ]]; then
		echo -n "❌"
		echo -e "$test_desc: Timestamp error: Non numerical\n\tTime of death: $time Last meal: $last_meal\n" >> philo_trace
	elif [[ ! $variance =~ ^[0-9]+$ ]]; then
		echo -n "❌"
		echo -e "$test_desc: Calculation error: Non numerical\n\tDifference: $variance\n" >> philo_trace
	elif [[ ! $philo =~ ^[0-9]+$ ]] || [[ ! $min =~ ^[0-9]+$ ]] || [[ ! $time_eat =~ ^[0-9]+$ ]] || [[ ! $time_sleep =~ ^[0-9]+$ ]] || [[ ! $eat =~ ^[0-9]+$ ]]; then
		echo -n "❌"
		echo -e "$test_desc: Input error: Non numerical\n\tPhilo no: $philo Time to die: $min Time to eat: $time_eat Time to sleep: $time_sleep No of times to eat: $eat\n" >> philo_trace
	elif ! tail -n 1 .julestestout | grep -q "died"; then
		echo -n "❌"
		echo -e "$test_desc: Philosopher did not die\n" >> philo_trace
	elif ((variance < min - 1)) || ((variance > max)); then
		echo -n "❌"
		echo -e "$test_desc: Philosopher did not die on time\n\tExpected: $min Actual: $variance\n" >> philo_trace
	else
		echo -n "✅"
	fi
}

trap "rm -rf .julesdeathlog .julesone .julesphilo1log .julesphilo2log .julesstderr .julestestfile .julestestout" EXIT

echo -e "
${PURPLE}#################################################################################################################${RESET}
${PURPLE}#${RESET}.${WHITE}########${RESET}..${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}####${RESET}.${WHITE}##${RESET}........${WHITE}#######${RESET}...${WHITE}######${RESET}...${WHITE}#######${RESET}..${WHITE}########${RESET}..${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}########${RESET}.${WHITE}########${RESET}...${WHITE}######${RESET}.${WHITE}${PURPLE}#${RESET}
${PURPLE}#${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}..${WHITE}##${RESET}..${WHITE}##${RESET}.......${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}....${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.......${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}....${WHITE}##${PURPLE}#${RESET}
${PURPLE}#${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}..${WHITE}##${RESET}..${WHITE}##${RESET}.......${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.......${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.......${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}......${PURPLE}#${RESET}
${PURPLE}#${RESET}.${WHITE}########${RESET}..${WHITE}#########${RESET}..${WHITE}##${RESET}..${WHITE}##${RESET}.......${WHITE}##${RESET}.....${WHITE}##${RESET}..${WHITE}######${RESET}..${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}########${RESET}..${WHITE}#########${RESET}.${WHITE}######${RESET}...${WHITE}########${RESET}...${WHITE}######${RESET}.${PURPLE}#${RESET}
${PURPLE}#${RESET}.${WHITE}##${RESET}........${WHITE}##${RESET}.....${WHITE}##${RESET}..${WHITE}##${RESET}..${WHITE}##${RESET}.......${WHITE}##${RESET}.....${WHITE}##${RESET}.......${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}........${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.......${WHITE}##${RESET}...${WHITE}##${RESET}.........${WHITE}##${PURPLE}#${RESET}
${PURPLE}#${RESET}.${WHITE}##${RESET}........${WHITE}##${RESET}.....${WHITE}##${RESET}..${WHITE}##${RESET}..${WHITE}##${RESET}.......${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}....${WHITE}##${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}........${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}##${RESET}.......${WHITE}##${RESET}....${WHITE}##${RESET}..${WHITE}##${RESET}....${WHITE}##${PURPLE}#${RESET}
${PURPLE}#${RESET}.${WHITE}##${RESET}........${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}####${RESET}.${WHITE}########${RESET}..${WHITE}#######${RESET}...${WHITE}######${RESET}...${WHITE}#######${RESET}..${WHITE}##${RESET}........${WHITE}##${RESET}.....${WHITE}##${RESET}.${WHITE}########${RESET}.${WHITE}##${RESET}.....${WHITE}##${RESET}..${WHITE}######${RESET}.${PURPLE}#${RESET}
${PURPLE}#################################################################################################################${RESET}
"

# If program doesn't exist then abort testing.

if [ ! -f "./philo" ]; then
	echo -e "${RED}Executable not found. Aborting test...${RESET}"
	exit 1
fi

# If trace already exists, add seperator to denote new test run

if [ -f "philo_trace" ]; then
	echo -e "\n============================================================\n" >> philo_trace
fi
echo -e "----- TRACE BEGINS -----\n" >> philo_trace
  
# Run basic tests to check error cases

echo -e "${PURPLE}--- ${WHITE}Basic Error Tests${PURPLE} ---\n${RESET}"
echo -e "-- Basic Error Tests --\n" >> philo_trace

echo -n > .julestestfile

run_err "No arguments" ""
run_err "1" 1
run_err "1 1" 1 1
run_err "1 1 1" 1 1 1
run_err "1 1 1 1 1 1" 1 1 1 1 1 1
run_err "a a a a" a a a a
run_err "-1 1 1 1 1" -1 1 1 1 1
run_err "1 -1 1 1 1" 1 -1 1 1 1
run_err "1 1 -1 1 1" 1 1 -1 1 1
run_err "1 1 1 -1 1" 1 1 1 -1 1
run_err "1 1 1 1 -1" 1 1 1 1 -1
run_err "-1 -1 -1 -1 -1" -1 -1 -1 -1 -1
run_err "0 1 1 1" 0 1 1 1
run_err "1 0 1 1" 1 0 1 1
run_err "1 1 0 1" 1 1 0 1
run_err "1 1 1 0" 1 1 1 0
run_err "1 1 1 1 0" 1 1 1 1 0
run_err "2147483648 100 60 60" 2147483648 100 60 60
run_err "2 2147483648 60 60" 2 2147483648 60 60
run_err "2 100 2147483648 60" 2 100 2147483648 60
run_err "2 100 60 2147483648" 2 100 60 2147483648
run_err "2 100 60 60 2147483648" 2 100 60 60 2147483648
rm -rf .julestestfile .julestestout .julesstderr

# Run tests for one philosopher

echo -e "${PURPLE}\n\n--- ${WHITE}One Philosopher Tests${PURPLE} ---\n${RESET}"
echo -e "-- One Philosopher Tests --\n" >> philo_trace

echo -e "1 died" > .julestestfile
run_one "1 200 60 60 1" 1 200 60 60 1
run_one "1 200 60 60 2" 1 200 60 60 2
run_one "1 100 60 60 2" 1 100 60 60 2
run_one "1 500 100 100 2" 1 500 100 100 2
run_one "1 500 100 100 10" 1 500 100 100 10
run_one "1 1000 250 250 2" 1 1000 250 250 2
run_one "1 100 150 150 10" 1 100 150 150 10
rm -rf .julestestout .julesone .julestestfile

# Run tests where no philosophers should die.

echo -e "${PURPLE}\n\n--- ${WHITE}No Death Tests${PURPLE} ---\n${RESET}"
echo -e "-- No Death Tests --\n" >> philo_trace

run_full "2 130 60 60 4" 2 130 60 60 4
run_full "2 300 100 100 4" 2 300 100 100 4
run_full "2 300 100 100 5" 2 300 100 100 5
run_full "3 200 65 65 5" 3 200 65 65 5
run_full "3 310 100 200 5" 3 310 100 200 5
run_full "4 210 100 100 10" 4 210 100 100 10
run_full "4 410 200 200 10" 4 410 200 200 10
run_full "4 600 200 200 5" 4 600 200 200 5
run_full "5 610 200 200 5" 5 610 200 200 5
run_full "5 600 100 200 5" 5 600 100 200 5
run_full "5 800 200 200 7" 5 800 200 200 7
run_full "5 300 60 60 15" 5 300 60 60 15
run_full "10 500 100 100 50" 10 500 100 100 50
run_full "11 900 150 90 20" 11 900 150 90 20

rm -rf .julestestout .julesphilo1log .julesphilo2log

# Run tests where a philosopher should die.

echo -e "${PURPLE}\n\n--- ${WHITE}Death Tests${PURPLE} ---\n${RESET}"
echo -e "-- Death Tests --\n" >> philo_trace

run_death "2 100 60 60 5" 2 100 60 60 5
run_death "2 100 100 100 5" 2 100 100 100 5
run_death "2 800 700 110 2" 2 800 700 110 2
run_death "3 210 100 100 5" 3 210 100 100 5
run_death "3 61 60 60 5" 3 61 60 60 5
run_death "4 190 100 100 5" 4 190 100 100 5
run_death "5 90 60 60 3" 5 90 60 60 3
run_death "10 199 100 100 10" 10 199 100 100 10
echo -e "\n"
rm -rf .julestestout .julesphilo1log .julesphilo2log .julesdeathlog
echo -e "---- TRACE ENDS ----" >> philo_trace
echo -e "${PURPLE}--- ${WHITE}Testing complete: philo_trace created${PURPLE} ---\n${RESET}"

# Created by Jules Pierce @ Hive Helsinki 2025/03/11 - https://github.com/Jules478
