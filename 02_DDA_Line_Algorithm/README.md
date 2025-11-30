# Lab 2: DDA Line Drawing Algorithm

## Overview
The **Digital Differential Analyzer (DDA)** is a simple line generation algorithm that uses floating-point arithmetic.

## Algorithm

```
Input: Two endpoints (x1, y1) and (x2, y2)

1. Calculate: dx = x2 - x1, dy = y2 - y1
2. Calculate: steps = max(|dx|, |dy|)
3. Calculate: xIncrement = dx / steps
             yIncrement = dy / steps
4. Set: x = x1, y = y1
5. For i = 0 to steps:
      Plot(round(x), round(y))
      x = x + xIncrement
      y = y + yIncrement
```

## Advantages
- Simple to understand and implement
- Faster than using line equation directly

## Disadvantages
- Uses floating-point arithmetic (slower than integer operations)
- Accumulated round-off errors for long lines
- Not as efficient as Bresenham's algorithm

## Usage
```
=== DDA Line Drawing Algorithm ===
Enter starting point (x1 y1): -50 -50
Enter ending point (x2 y2): 50 50
```

## Sample Inputs to Try
| Start Point | End Point | Line Type |
|-------------|-----------|-----------|
| (0, 0) | (50, 25) | Gentle slope |
| (0, 0) | (25, 50) | Steep slope |
| (-50, 0) | (50, 0) | Horizontal |
| (0, -50) | (0, 50) | Vertical |
| (-50, -50) | (50, 50) | 45° diagonal |

## Compilation
```bash
g++ dda_line.cpp -o dda_line -lopengl32 -lglu32 -lfreeglut
```
