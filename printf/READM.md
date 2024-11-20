<h1 align="center">
	✏️ printf
</h1>

<p align="center">
	<b><i>Implementation of printf, a formatted output function in C.</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About	</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<!-- <a href="#-testing">Testing</a> -->
</h3>

---

## 💡 About the project

> The printf project involves implementing a custom version of the standard C library function printf. This function provides formatted output, which is essential for displaying data in a controlled and user-friendly manner. The goal of the project is to mimic the behavior of the original printf function, understanding its internals, and managing its formatting capabilities.


## 🛠️ Features of the Project

- Supports various format specifiers, including:
 - %c: Print a single character.
 - %s: Print a string of characters.
 - %p: Print a memory address.
 - %d/%i: Print an integer in decimal.
 - %u: Print an unsigned integer.
 - %x/%X: Print a number in hexadecimal (lowercase/uppercase).
 - %%: Print a percentage sign.
- Handles flags like -, 0, ., and width/precision for formatting output.
- Modular and reusable code structure to simplify the addition of new specifiers or flags.
- Efficient memory management, ensuring no memory leaks during execution.


### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile, go to the library path and run:

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
**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

## Learning Goals
- This project helps develop:

 - Low-level programming skills: Gain deeper knowledge of how functions like printf handle arguments using va_list and variable argument functions (stdarg.h).
 - String manipulation: Master techniques for formatting and processing strings.
 - Algorithm design: Create efficient solutions for implementing custom flags and specifiers.
 - Code optimization: Write clean, modular, and performance-optimized C code.
