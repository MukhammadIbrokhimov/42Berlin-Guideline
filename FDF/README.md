# FDF Project - 42 Network

## Description
This project is a part of the 42 Network curriculum, where we are tasked with creating a program that renders 3D data onto a 2D plane using graphical libraries in C. The program reads a map of integers and visualizes it as a 3D isometric projection. The user can interact with the map, applying rotations, zooming in and out, and moving the view to explore the data in 3D space.

This project is designed to help us learn graphical programming, mathematical concepts like projections and transformations, and the use of libraries such as MiniLibX.

## Requirements
- C programming language (compilation with `gcc`)
- MiniLibX graphical library (provided by 42)
- Linux-based environment for compiling and running
- Makefile to compile the project

## Features
- **3D Map Visualization**: The program reads a file containing a map and displays it as a 3D projection.
- **Interactive Controls**:
  - Arrow keys for movement (up/down/left/right).
  - Zoom in and out using the '+' and '-' keys.
  - Rotation using the 'A', 'S', 'D', and 'W' keys.
  - Option to quit using the 'ESC' key.
- **Dynamic Map Rendering**: The program supports dynamic adjustment of the map's perspective, allowing for a more interactive experience.
- **Error Handling**: The program handles edge cases such as invalid input files, incorrect formatting, and other potential issues.

## Compilation & Installation

To compile the project, simply run:

```bash
make
```
# FDF Project

## Description
This project generates an executable file called `fdf` to visualize a 3D map using graphical rendering.

## Dependencies
- **MiniLibX**: A graphical library used for rendering (provided by the 42 network).
- **libft**: The 42 library containing useful functions, such as `ft_printf` and string manipulation utilities.

If you do not have **MiniLibX** installed, you can follow the official 42 guidelines to set up the environment properly.

## Running the Program
Once the project is compiled, you can run the program using the following command:

```bash
./fdf <path_to_map_file>

```

# Project Structure

├── src/
│   ├── main.c              # Entry point of the program
│   ├── map.c               # Functions to read and parse the map
│   ├── render.c            # Functions to render the map
│   └── utils.c             # Helper functions (e.g., error handling)
├── includes/
│   └── fdf.h               # Header file containing function prototypes
├── Makefile                # Makefile for compilation
└── README.md               # Project documentation

