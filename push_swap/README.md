<h1 align="center">
	✏️ push_swap
</h1>

<p align="center">
	<b><i>A project to sort a stack of integers using the least number of operations.</i></b><br>
</p>

<h3 align="center">
		<a href="#about-the-project">About</a>
		<span> · </span>
		<a href="#features-of-the-project">Features</a>
		<span> · </span>
		<a href="#requirements">Requirements</a>
		<span> · </span>
		<a href="#instructions">Instructions</a>
		<span> · </span>
		<a href="#learning-goals">Learning Goals</a>
		<span> · </span>
		<a href="#project-structure">Project Structure</a>
</h3>

---

## 💡 About the project

> The `push_swap` project involves sorting a stack of integers using a limited set of operations. The goal of this project is to practice efficient sorting algorithms by implementing them yourself, while also learning to minimize the number of operations. It helps improve your understanding of data structures and algorithms in C.

The main challenge of the project is to sort the integers using only a small set of operations, including:
- **Push**: `pa`, `pb` (push the top element from one stack to the other).
- **Swap**: `sa`, `sb`, `ss` (swap the top two elements of a stack).
- **Rotate**: `ra`, `rb`, `rr` (rotate the stack, moving the top element to the bottom).
- **Reverse Rotate**: `rra`, `rrb`, `rrr` (reverse rotate the stack, moving the bottom element to the top).

The bonus part of the project adds additional complexity by allowing a graphical visualization of the sorting process and handling interactive commands for manipulating the stacks.

## 🌟 Features of the Project

- Implements a sorting algorithm with the least number of operations.
- Efficient stack management with operations like push, swap, rotate, and reverse rotate.
- Supports both interactive and non-interactive modes.
- Handles sorting for stacks of arbitrary size.
- Optimizes the number of operations to ensure the best performance.

## 🛠️ Requirements

The project is written in C and requires the following tools and libraries to run:
- **`gcc`** compiler
- **Standard C libraries**, including `stdlib.h`, `unistd.h`, and `stdio.h`.

## 🔧 Instructions

### 1. Compiling the project

To compile the project, navigate to the project directory and run:

```shell
$ make
```

Other make-files-commands:
```shell
$ make bonus
$ make clean
$ make fclean
$ make re
```
**2. Using the program**

After compiling, you can use the push_swap program to sort a list of integers:
```
$ ./push_swap 5 3 1 4 2
```
or
```
$ ./push_swap "5 3 1 4 2"
```
This will output the list of operations needed to sort the integers in the most efficient way.

For Bonus
```
$ ./checker 5 4 1 3
```
Where instructions.txt contains the list of operations to apply, such as:
```
pb
ra
pa
ra
```
The program will output "OK" if the stacks are correctly sorted or "KO" if the operations were incorrect, "Error" when feeding garbage values.

## 🎯 Learning Goals
- This project helps develop:
	- Algorithm design: Develop and implement sorting algorithms that are optimized for performance.
	- Data structures: Work with stacks and understand their operations and uses.
	- Efficiency: Learn how to minimize operations for better performance in sorting.
	- Memory management: Efficient use of memory and dynamic allocation in C.

## 📂 Project Structure
```
.
├── Makefile
├── README.md
├── bonus
│   └── main_bonus.c
├── includes
│   ├── push_swap.h
│   └── push_swap_bonus.h
└── src
    ├── general_functions
    │   ├── free_things.c
    │   └── std_error.c
    ├── init_stack.c
    ├── init_stack_by_string.c
    ├── instructions
    │   ├── index.c
    │   ├── push.c
    │   ├── reverse_rotations.c
    │   ├── rotations.c
    │   └── swaps.c
    ├── main.c
    ├── node_operation.c
    ├── ps_split.c
    ├── push_around.c
    ├── set_info
    │   ├── set_info_to_stack_a.c
    │   └── set_info_to_stack_b.c
    ├── sort_stack.c
    └── stack_utils.c
```
