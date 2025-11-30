# Lab 1: Basic OpenGL Primitives

## Overview
This lab introduces the fundamental drawing primitives in OpenGL/GLUT.

## Concepts Covered
- Setting up OpenGL window
- Drawing points using `GL_POINTS`
- Drawing lines using `GL_LINES`
- Drawing triangles using `GL_TRIANGLES`
- Drawing quadrilaterals using `GL_QUADS`
- Drawing polygons using `GL_POLYGON`
- Using colors with `glColor3f()`

## Output
The program displays:
- X and Y coordinate axes (black lines)
- A blue point at (0.5, 0.5)
- A yellow point at origin (0, 0)
- A green triangle in bottom-left
- A red square in top-left
- A cyan rectangle
- A magenta pentagon in bottom-right

## Key Functions Used
| Function | Description |
|----------|-------------|
| `glBegin()` / `glEnd()` | Define primitive type |
| `glVertex2f()` | Specify vertex coordinates |
| `glColor3f()` | Set RGB color (0.0 to 1.0) |
| `glPointSize()` | Set point size in pixels |
| `glClearColor()` | Set background color |
| `glFlush()` | Force execution of GL commands |

## Compilation
```bash
g++ basic_primitives.cpp -o basic_primitives -lopengl32 -lglu32 -lfreeglut
```
