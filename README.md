# Computer Graphics Lab - OpenGL/GLUT Programs

This repository contains AIUB Computer Graphics lab programs implemented using **OpenGL** and **GLUT** library in **C++**.

## 📚 Course Information
- **Course**: Computer Graphics
- **Course Teacher**: DIPTA JUSTIN GOMES
- **Tools Used**: OpenGL, GLUT, Code::Blocks IDE

---

## 📁 Project Structure

```
COMPUTER-GRAPHICS/
├── .gitignore               # Specifies intentionally untracked files to ignore.
├── GraphicsProject/         # Contains various smaller, standalone graphics projects
│   ├── InteractiveTransformations/
│   │   ├── Makefile
│   │   └── main.cpp
│   ├── ClippingAlgorithms/
│   │   ├── ...
│   └── ...                  # More individual graphics concept implementations.
├── MID-TERM/                # Dedicated to projects or assignments related to a mid-term milestone.
│   ├── RasterizerProject/
│   │   ├── Makefile
│   │   └── main.cpp
│   └── ...                  # Specific larger projects or coursework.
└── README.md                # This file.
```


## 📸 Output Examples
## 📸 scenario 1
<img width="1920" height="984" alt="image" src="https://github.com/user-attachments/assets/e0dc709a-e949-4f34-a6a1-99f689e6d4f7" />
<img width="1920" height="982" alt="image" src="https://github.com/user-attachments/assets/ac066bb5-ba15-484d-b9d9-6661b14d2ec9" />
<img width="1920" height="987" alt="image" src="https://github.com/user-attachments/assets/348dabe7-0653-4d61-b1b0-ffaa637f24c3" />
<img width="1920" height="990" alt="image" src="https://github.com/user-attachments/assets/2e20e750-e6b8-4dd1-875f-f536c2de29b7" />
<img width="1920" height="984" alt="image" src="https://github.com/user-attachments/assets/a32a1af4-7de9-4830-91d6-3acfa75632ad" />

## 📸 scenario 2
<img width="1917" height="984" alt="image" src="https://github.com/user-attachments/assets/08ebe17a-6617-4353-9df3-4aa610c022b3" />
<img width="1920" height="981" alt="image" src="https://github.com/user-attachments/assets/e8b8c97f-5b87-4776-96bf-3927c7b2b448" />
<img width="1920" height="984" alt="image" src="https://github.com/user-attachments/assets/5546a751-eafa-4476-8251-b97db0059366" />
<img width="1920" height="985" alt="image" src="https://github.com/user-attachments/assets/e0789121-7873-43eb-89ea-aa7e575c076a" />

## 📸 scenario 3
<img width="1920" height="981" alt="image" src="https://github.com/user-attachments/assets/063afa6e-5afc-4bf3-98e4-fd32152871f4" />
<img width="1920" height="988" alt="image" src="https://github.com/user-attachments/assets/07608ef1-02b2-40ea-85e2-b079a3dd4a18" />
<img width="1920" height="972" alt="image" src="https://github.com/user-attachments/assets/2d1e7cdc-3ddd-402a-a13f-3f0b39570e4c" />


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
