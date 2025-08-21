# 🎮 cub3D - My First RayCaster

> *"Relive the golden age of gaming with your own Wolfenstein 3D-inspired raycaster!"*

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![MinilibX](https://img.shields.io/badge/MinilibX-Graphics-red?style=flat)](https://github.com/42Paris/minilibx-linux)

## 🚀 Overview

**cub3D** is a 3D graphics programming project that recreates the legendary **Wolfenstein 3D** experience using **ray-casting** techniques. This project pays homage to the world's first FPS game (1992) by Id Software, while teaching fundamental 3D graphics programming concepts.

Navigate through mysterious mazes from a first-person perspective, where mathematics meets visual artistry to create the illusion of three-dimensional space on a 2D screen.

## ✨ Features

### 🎯 Core Functionality
- **Real-time ray-casting engine** - Experience smooth 3D rendering
- **Texture mapping** - Dynamic wall textures based on cardinal directions
- **First-person navigation** - WASD movement with arrow key rotation  
- **Interactive environment** - Explore mazes with realistic perspective
- **Custom map support** - Load your own maze configurations
- **Optimized rendering** - Efficient graphics pipeline for smooth gameplay

### 🎨 Visual Elements
- **Directional textures** - Unique wall appearances for North, South, East, West
- **Customizable colors** - Configurable floor and ceiling aesthetics
- **Smooth animations** - Fluid movement and rotation mechanics
- **Window management** - Professional GUI handling with proper cleanup

### 🗺️ Map System
- **Flexible parsing** - Support for custom `.cub` map files
- **Robust validation** - Comprehensive error handling and map verification
- **Simple format** - Easy-to-create maze layouts using basic characters
- **Boundary detection** - Automatic wall collision and map boundary enforcement

## 🛠️ Technical Implementation

🏗️ Architecture
├── Ray-casting Engine    → Core 3D rendering mathematics
├── Texture Pipeline     → Graphics memory and image processing
├── Input Management     → Real-time keyboard/mouse handling
├── Map Parser          → Configuration file processing
└── Game Loop           → Event-driven program lifecycle

### 📋 Technologies Used
- **Language:** C (following 42 School Norm)
- **Graphics:** MinilibX library
- **Mathematics:** Linear algebra, trigonometry, vector calculations
- **Memory Management:** Manual heap allocation with leak prevention
- **Build System:** Custom Makefile with proper dependency management

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` `A` `S` `D` | Move through the maze |
| `←` `→` | Rotate camera left/right |
| `ESC` | Exit program |

## 🗂️ Map Configuration

Create your own adventures with simple `.cub` files:
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm
F 220,100,0    # Floor color (RGB)
C 225,30,0     # Ceiling color (RGB)
111111111
100000001
101010101
100000001
1000N0001
111111111

## 🚀 Getting Started

### Prerequisites
- GCC compiler with `-Wall -Wextra -Werror` flags
- MinilibX library
- Math library (`-lm`)
- X11 development libraries (Linux)

### Installation & Usage

```bash
# Clone the repository
git clone https://github.com/yourusername/cub3D.git
cd cub3D
```

# Compile the project
```
make
```

# Run with a map file
./cub3D maps/sample.cub
Building
```make          # Compile the project
make clean    # Remove object files
make fclean   # Remove all generated files
make re       # Recompile everything
make bonus    # Compile with bonus features
```
🎯 Project Goals
This project serves as an introduction to:

3D Graphics Programming - Understanding ray-casting and rendering pipelines
Mathematical Applications - Practical use of geometry and trigonometry
Game Development - Real-time graphics and user interaction
System Programming - Memory management and performance optimization
Collaborative Development - Team-based software engineering practices

🏆 Bonus Features

🎯 Wall Collisions - Realistic movement boundaries
🗺️ Minimap System - Real-time navigation aid
🚪 Interactive Doors - Open/close mechanics
🎭 Animated Sprites - Dynamic game elements
🖱️ Mouse Controls - Enhanced camera manipulation

👥 Team Development
This project is designed for collaborative development between two programmers:

🎨 Graphics Engineer - Ray-casting, rendering, textures
🎮 Game Systems Engineer - Input handling, parsing, game logic

🎓 Learning Outcomes
By completing this project, developers gain hands-on experience with:

Low-level graphics programming
Mathematical problem-solving in software
Real-time system constraints
Memory-efficient algorithm design
Cross-platform development considerations

📄 License
This project is part of the 42 School curriculum. Educational use only.

Built with ❤️ by aspiring game developers at 42 School
