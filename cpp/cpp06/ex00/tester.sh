#!/bin/bash

# Path to your executable
EXEC=./convert

# Test inputs
inputs=(
  "A"
  "!"
  "9"
  "42"
  "3.14"
  "0.0"
  "-123.456"
  "+1"
  "1e10"
  "-2.5e-3"
  "3.40282e+38"
  "nan"
  "inf"
  "-inf"
  "nanf"
  "inff"
  "-inff"
  "1e5000"
  "-1e5000"
  "3.5e39"
  "-3.5e39"
  ""
  "hello"
  "123abc"
  "--42"
  "++1"
  "42.42.42"
  " 42"
  "42 "
  "3,14"
  "1e9999"
)

subject_inputs=(
	0
	nan
	42.0f
)

echo "Starting tests..."

for input in "${inputs[@]}"; do
  echo "----------------------------------"
  echo "Input: \"$input\""
  $EXEC "$input"
done

echo "Tests completed."

echo "----------------------------------"
echo "Subject tests..."
for input in "${subject_inputs[@]}"; do
	echo "----------------------------------"
	echo "Input: $input"
	$EXEC "$input"
done
