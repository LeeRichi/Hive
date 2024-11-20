<h1 align="center">
	✏️ so_long
</h1>

<p align="center">
	<b><i>A 2D game built with MLX, showcasing pathfinding and game mechanics.</i></b><br>
</p>

<h3 align="center">
		<a href="#-about-the-project">About</a>
		<span> · </span>
		<a href="#-features-of-the-project">Features</a>
		<span> · </span>
		<a href="#-requirements">Requirements</a>
		<span> · </span>
		<a href="#-instructions">Instructions</a>
		<span> · </span>
		<a href="#-learning-goals">Learning Goals</a>
		<span> · </span>
		<a href="#-project-structure">Project Structure</a>
</h3>

---

## 💡 About the project

> so_long is a 2D game built using the MLX library, featuring pathfinding and various game mechanics. In this game, the player navigates through a map, collecting items and avoiding obstacles. The game mechanics are designed to test your understanding of grid-based pathfinding and interaction with graphical elements.

The main features of the game include:
- **Pathfinding**: The player must find a route through a map with obstacles and goals.
- **Game mechanics**: Interacting with items, enemies, and other game elements within the environment.
- **Graphics**: Displaying a 2D game world using MLX for graphical rendering.

## 🌟 Features of the Project

- 2D game with an interactive map.
- Pathfinding mechanics to navigate through obstacles.
- Collect items and reach goals while avoiding enemies.
- Dynamic display with graphics rendered using MLX.
- Handle user inputs to control the player's movements.

## 🛠️ Requirements

The project is written in C and uses the MLX library for graphics rendering. It requires the following tools and libraries to run:
- **`gcc`** compiler
- MLX library (clone path is included in Makefile)
- **Standard C libraries**, including `stdlib.h`, `unistd.h`, and `stdio.h`.

## 🔧 Instructions

### 1. Compiling the project

To compile the project, navigate to the project directory and run:<br>
>Tip: Some users might encounter errors when running the following commands in the VSCode terminal on Mac M1. However, using the original Terminal app on macOS can resolve the issue.

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
$ ./so_long maps/valid/5x7.ber
```
or
```
$ ./so_long maps/invalid/non_rec.ber
```
Where maps/my_map.ber is the map file you want to use for your game. The player will be able to move around and interact with the game world based on the map configuration.

## 🎯 Learning Goals
- This project helps develop:
	- Game development: Learn the fundamentals of game mechanics and pathfinding.
	- Graphical programming: Understand how to render 2D graphics using MLX.
	- Memory management: Efficiently allocate and deallocate memory for game elements and resources.
	- Algorithm design: Develop algorithms for pathfinding and handling user inputs.

## 📂 Project Structure
```
.
├── check_block.c
├── deep_copy.c
├── delete.c
├── draw_camera.c
├── draw_ground.c
├── flood_packs.c
├── img_init.c
├── init_map.c
├── loop_temp_map.c
├── main.c
├── map_checker.c
├── valid_movements.c
├── win_exit.c
├── window_init.c
└── window_init_helpers.c
```
## screen shot
<img width="962" alt="Screenshot 2024-11-20 at 3 30 23 PM" src="https://github.com/user-attachments/assets/c59e7a9d-9cf4-4cba-8e22-54043398de62">
