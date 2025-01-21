<h1 align="center">
	FDF
</h1>

<p align="center">
	<b><i>A simplified 3D graphic representation of a relief landscape.</i></b><br>
</p>

Need install on Linux ↙️

## Description
This project is a part of the 42 Network curriculum, where we are tasked with creating a program that renders 3D data onto a 2D plane using graphical libraries in C. The program reads a map of integers and visualizes it as a 3D isometric projection. The user can interact with the map, applying rotations, zooming in and out, and moving the view to explore the data in 3D space.

This project is designed to help us learn graphical programming, mathematical concepts like projections and transformations, and the use of libraries such as MiniLibX.

---

## Aims of the Project

The primary objectives of this project are:

- **Learning graphical programming**: Understanding how to manipulate graphical elements such as pixels, lines, and shapes.
- **Handling 3D data**: Translating 3D coordinates into a 2D plane using **isometric projection**.
- **Matrix transformations**: Understanding and applying transformations such as rotation, scaling, and translation on 3D data.
- **Interactive controls**: Implementing user interaction for rotating, zooming, and translating the 3D view.
- **Using MiniLibX**: Gaining experience with the **MiniLibX** graphical library (provided by the 42 network).
- **Optimizing performance**: Managing and rendering large 3D maps efficiently.
- **File handling**: Reading data from an input file, parsing it, and displaying it in a graphical interface.

---

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

## Algorithms for Drawing Lines
In FdF, you’ll need algorithms to draw the lines between the points (from the 3D data). 
- **Three common algorithms to do**: this are:
- Wu’s Algorithm: Best for drawing smooth lines (anti-aliasing), but it's slower and more complex. If you want high-quality visuals, this is a good choice. [doc here]​
- Bresenham’s Algorithm: This is faster and uses integer math, making it more efficient. It's great for performance.  [doc here]​
- DDA (Digital Differential Analyzer): A simpler method, but not as fast as Bresenham and not as smooth as Wu’s.  [doc here]​
Advice: If you want a good balance of quality and speed, go for Bresenham’s Algorithm or Wu's Algorthm. It’s the most commonly used for projects like FdF. Here was used Wu's Algrothm


## Compilation & Installation

To compile the project, simply run:

```bash
make
```
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

## Examples

### Simple example of functionality
The following is an example of a .fdf file we use as an input for our program:
```
0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 1 2 3 4 5 6 7
0 0 0 0 0 1 2 3 4 5 6
0 0 0 0 0 0 1 2 3 4 5
0 0 0 0 0 0 0 1 2 3 4
0 0 0 0 0 0 0 0 1 2 3
0 0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0 1
```
which produces the following:

![example (2)](https://user-images.githubusercontent.com/21006147/190404000-e2acf21e-72f6-449b-afe2-5c0bdd076f29.gif)

### Example of rotation, translation, zoom, flattening and perspective changes

![fdf480](https://user-images.githubusercontent.com/21006147/190404352-288d7bf1-5f43-4e2d-8033-f16bca534ca6.gif)

### Example of map with custom colors

<img width="1236" alt="Screen Shot 2022-09-15 at 2 34 42 PM" src="https://user-images.githubusercontent.com/21006147/190404961-988cedf9-bed6-417f-bed3-eb5dc2b7afda.png">

### Example with large map
<img width="1910" alt="Screen Shot 2022-09-15 at 2 38 15 PM" src="https://user-images.githubusercontent.com/21006147/190406149-d0d13cb6-c3eb-4594-abf8-d22c5b005485.png">

