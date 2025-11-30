# Lab 4: Circle Drawing Algorithms

## Overview
This lab covers different approaches to drawing circles in OpenGL.

## Files

### 1. `midpoint_circle.cpp` - Midpoint Circle Algorithm
The most efficient method using 8-way symmetry and integer arithmetic.

### 2. `basic_circle.cpp` - Trigonometric Method
Uses `sin()` and `cos()` functions - simpler but less efficient.

### 3. `bangladesh_flag.cpp` - Practical Application
Combines rectangles and filled circles to create the Bangladesh flag.

---

## Midpoint Circle Algorithm

### Concept: 8-Way Symmetry
A circle has 8-way symmetry. For any point (x, y) on the circle, these 8 points also lie on the circle:
```
(x, y)   (-x, y)   (x, -y)   (-x, -y)
(y, x)   (-y, x)   (y, -x)   (-y, -x)
```

### Algorithm
```
Input: Center (xc, yc), Radius r

1. Set: x = 0, y = r
2. Initial decision parameter: p = 1 - r
3. Plot 8 symmetric points
4. While x < y:
      x++
      If p < 0:
         p = p + 2x + 1    (Choose East pixel)
      Else:
         y--
         p = p + 2(x-y) + 1  (Choose Southeast pixel)
      Plot 8 symmetric points
```

### Why This Works
- We only calculate points for 1/8th of the circle (one octant)
- The other 7 parts are drawn using symmetry
- Decision parameter determines whether to move East or Southeast

---

## Trigonometric Method

### Filled Circle (GL_TRIANGLE_FAN)
```cpp
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);  // Center
    for (int i = 0; i <= segments; i++) {
        float angle = 2 * PI * i / segments;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
glEnd();
```

### Hollow Circle (GL_LINE_LOOP)
```cpp
glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= segments; i++) {
        float angle = 2 * PI * i / segments;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
glEnd();
```

---

## Comparison

| Method | Arithmetic | Speed | Accuracy | Use Case |
|--------|-----------|-------|----------|----------|
| Midpoint | Integer | Fast | Pixel-perfect | Rasterization |
| Trigonometric | Floating-point | Slower | Smooth curves | Quick prototyping |

---

## Bangladesh Flag Details
- **Green Rectangle**: RGB(0, 102, 64) - Represents the lush greenery
- **Red Circle**: RGB(240, 41, 41) - Represents the rising sun and blood of martyrs
- **Circle Position**: Slightly left of center (ratio: 9:21 from left edge)

## Compilation
```bash
g++ midpoint_circle.cpp -o midpoint_circle -lopengl32 -lglu32 -lfreeglut
g++ basic_circle.cpp -o basic_circle -lopengl32 -lglu32 -lfreeglut
g++ bangladesh_flag.cpp -o bangladesh_flag -lopengl32 -lglu32 -lfreeglut
```
