# Computer Graphics Lab - OpenGL/GLUT Programs

This repository contains Computer Graphics lab programs implemented using **OpenGL** and **GLUT** library in **C++**.

## 📚 Course Information
- **Course**: Computer Graphics
- **Student ID**: 22-49760-3
- **Tools Used**: OpenGL, GLUT, Code::Blocks IDE

---

## 📁 Project Structure

```
├── 01_Basic_Primitives/
│   └── basic_primitives.cpp      # Points, Lines, Triangles, Rectangles, Polygons
│
├── 02_DDA_Line_Algorithm/
│   └── dda_line.cpp              # Digital Differential Analyzer Line Drawing
│
├── 03_Midpoint_Line_Algorithm/
│   └── midpoint_line.cpp         # Bresenham's Midpoint Line Drawing Algorithm
│
├── 04_Circle_Algorithms/
│   ├── midpoint_circle.cpp       # Midpoint Circle Drawing Algorithm
│   ├── basic_circle.cpp          # Circle using Trigonometric Functions
│   └── bangladesh_flag.cpp       # Practical Application - Bangladesh Flag
│
└── README.md
```

---

## 🔬 Lab Contents

### Lab 1: Basic OpenGL Primitives
Learn the fundamentals of OpenGL by drawing basic shapes:
- Points (`GL_POINTS`)
- Lines (`GL_LINES`)
- Triangles (`GL_TRIANGLES`)
- Quadrilaterals (`GL_QUADS`)
- Polygons (`GL_POLYGON`)

### Lab 2: DDA Line Algorithm
Implementation of the **Digital Differential Analyzer (DDA)** algorithm for drawing lines:
- Handles all slopes (gentle and steep)
- User input for start and end coordinates
- Coordinate axes visualization

### Lab 3: Midpoint Line Algorithm
Implementation of **Bresenham's Midpoint Line Algorithm**:
- Integer-only arithmetic (more efficient than DDA)
- Handles all octants
- Symmetric line drawing demonstration

### Lab 4: Circle Drawing Algorithms
Multiple approaches to drawing circles:
- **Midpoint Circle Algorithm** - Efficient integer-based circle drawing using 8-way symmetry
- **Trigonometric Method** - Circle drawing using sine and cosine functions
- **Bangladesh Flag** - Practical application combining rectangles and filled circles

---

## 🛠️ How to Run

### Prerequisites
1. Install **Code::Blocks** IDE (or any C++ IDE)
2. Install **OpenGL** and **GLUT** libraries
3. For Windows: Copy `glut32.dll` to `C:\Windows\System32`

### Compilation (Using g++)
```bash
g++ filename.cpp -o output -lopengl32 -lglu32 -lfreeglut
```

### Running in Code::Blocks
1. Create a new Console Application project
2. Add the `.cpp` file to your project
3. Link the libraries: `opengl32`, `glu32`, `glut32`
4. Build and Run (F9)

---

## 📖 Algorithm Explanations

### DDA Algorithm
The DDA algorithm calculates intermediate points between two endpoints by:
1. Calculate `dx = x2 - x1` and `dy = y2 - y1`
2. Determine steps = max(|dx|, |dy|)
3. Calculate increments: `xInc = dx/steps`, `yInc = dy/steps`
4. Plot rounded coordinates in each step

### Midpoint Line Algorithm
More efficient than DDA as it uses only integer arithmetic:
1. Calculate decision parameter `d = 2dy - dx`
2. If `d < 0`: Choose East pixel, update `d += 2dy`
3. If `d >= 0`: Choose Northeast pixel, update `d += 2(dy-dx)`

### Midpoint Circle Algorithm
Uses 8-way symmetry to draw circles efficiently:
1. Start at (0, r), decision parameter `p = 1 - r`
2. If `p < 0`: Choose East pixel, `p += 2x + 1`
3. If `p >= 0`: Choose Southeast pixel, `p += 2(x-y) + 1`
4. Plot 8 symmetric points for each calculated point

---

## 📸 Output Examples

| Program | Description |
|---------|-------------|
| Basic Primitives | Draws points, axes, triangle, rectangle, pentagon |
| DDA Line | Interactive line drawing with user input |
| Midpoint Line | Two symmetric lines using midpoint algorithm |
| Midpoint Circle | Circle centered at (-2, -2) with radius 50 |
| Bangladesh Flag | Complete flag with pole and red circle |

---

## 🔗 References
- [OpenGL Documentation](https://www.opengl.org/documentation/)
- [GLUT Reference Manual](https://www.opengl.org/resources/libraries/glut/)
- Computer Graphics: Principles and Practice - Foley, van Dam, et al.

---

## 📝 License
This project is for educational purposes. Feel free to use and modify for learning.

---

*Made with ❤️ for Computer Graphics Course*
