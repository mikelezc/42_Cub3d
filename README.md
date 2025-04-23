# 🎮 cub3D - Raycasting Game Engine

## Overview
cub3D is a raycasting engine inspired by the legendary Wolfenstein 3D game, developed as part of the 42 School curriculum. This project implements a simple 3D rendering technique that simulates a first-person perspective in a maze-like environment.

## Features
- **Basic Version**
  - Raycasting engine for 3D wall rendering
  - Textured walls with different textures for each direction
  - Player movement (walk forward/backward and strafe left/right)
  - Camera rotation

- **Bonus Version**
  - Minimap for spatial awareness
  - Mouse control for camera movement
  - Interactive doors
  - Weapon animations
  - Wall collision detection
  - Sprint ability
  - Distance-based lighting effects

## Requirements
- Linux or macOS operating system
- GCC compiler
- Make
- X11 library
- OpenGL library

## Compilation

### Compile the basic version
```bash
make
```
### Compile the bonus version with extended features
```bash
make bonus
```

## Usage

### Basic Version
```bash
./cub3D maps/map.cub
```

### Bonus Version
```bash
./cub3D_bonus maps/map.cub
```

### Map File Format
Map files have a .cub extension and must follow this format:

```
NO ./textures/north_texture.xpm
SO ./textures/south_texture.xpm
WE ./textures/west_texture.xpm
EA ./textures/east_texture.xpm

F 220,100,0
C 225,30,0

1111111111111
1000000000001
1000000000001
1000000N00001
1000000000001
1000000000001
1111111111111
```

- `NO`, `SO`, `WE`, `EA`: Paths to wall textures for each direction
- `F`: RGB color for the floor (R,G,B)
- `C`: RGB color for the ceiling (R,G,B)
- Map layout uses the following characters:
  - `1`: Wall
  - `0`: Empty space
  - `N`, `S`, `E`, `W`: Player starting position and orientation
  - `D`: Door (bonus version)
  - `d`: Open door (bonus version)

## Controls

### Basic Version
- `W`, `S`: Move forward/backward
- `A`, `D`: Strafe left/right
- `←`, `→`: Rotate camera left/right
- `ESC`: Exit game

### Bonus Version
- Basic controls plus:
- Mouse movement: Rotate camera
- Left mouse click: Interact/attack
- `SPACE`: Toggle doors
- `SHIFT`: Sprint
- `M`: Toggle minimap
- `H`: Toggle help screen

## Development Stack
- C programming language
- miniLibX graphic library
- Mathematical concepts: raycasting, vector geometry, collision detection
- Software design patterns for game development

## Acknowledgements
- 42 School for the project specification
- id Software for the inspiration (Wolfenstein 3D)

## Authors

- mlezcano - [GitHub Profile](https://github.com/mikelezc)
- ampjimen - [GitHub Profile](https://github.com/Amparojd)
  
