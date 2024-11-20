<h1 align="center">
	✏️ get_next_line
</h1>

<p align="center">
	<b><i>A function to read lines from file descriptors, character by character.</i></b><br>
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
</h3>

---

## 💡 About the project

> The `get_next_line` project involves implementing a function that reads a line from a file descriptor, returning the line (up to the next newline character or EOF) one character at a time. The goal of the project is to understand and handle memory management effectively and to work with system calls and file descriptors in C.

## 🌟 Features of the Project

- Reads one line at a time from a file descriptor.
- Handles multiple file descriptors at once.
- Manages memory efficiently with dynamic allocation to store the line.
- Returns the line up to a newline character or the end of the file (EOF).
- Works with large files, avoiding memory overflow by reading in chunks.
- Handles edge cases, such as empty lines, multiple newlines, and EOF.

## 🛠️ Requirements

The function is written in C language and needs the following tools and libraries to run:
- **`gcc`** compiler
- **Standard C libraries**, including `unistd.h` for file handling.

## 🔧 Instructions

**1. Compiling the library**

To compile the library, navigate to the project directory and run:

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

```
#include "get_next_line.h"
```

Then, you can use get_next_line() to read lines from a file descriptor, such as:

```
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line); // Don't forget to free the memory!
}

close(fd);
```

## 🎯 Learning Goals
- This project helps develop:
	- File handling in C: Gain experience with file descriptors and system calls like read().
	- Memory management: Understand dynamic memory allocation, freeing, and reusing memory.
	- Edge case handling: Learn how to handle corner cases like empty files, EOF, and lines with no newlines.
	- Modular code structure: Implement a reusable and efficient function to handle file reading across different scenarios.
