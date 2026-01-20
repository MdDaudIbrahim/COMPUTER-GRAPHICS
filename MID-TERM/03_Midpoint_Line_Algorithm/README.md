# Lab 3: Midpoint Line Drawing Algorithm

## Overview
The **Midpoint Line Algorithm** (also known as **Bresenham's Line Algorithm**) is an efficient line drawing algorithm that uses only integer arithmetic, making it faster than DDA.

## Algorithm

### For Gentle Slope (|m| ≤ 1, i.e., dx ≥ dy):
```
Input: Two endpoints (x1, y1) and (x2, y2)

1. Calculate: dx = |x2 - x1|, dy = |y2 - y1|
2. Initial decision parameter: d = 2*dy - dx
3. Set: incrementE = 2*dy (for East)
        incrementNE = 2*(dy - dx) (for Northeast)
4. For x from x1 to x2:
      Plot(x, y)
      If d < 0:
         d = d + incrementE  (Choose East pixel)
      Else:
         d = d + incrementNE (Choose Northeast pixel)
         y = y + 1
```

### For Steep Slope (|m| > 1, i.e., dy > dx):
- Swap roles of x and y
- Iterate over y values instead of x

## Why Midpoint Algorithm is Better than DDA

| Aspect | DDA | Midpoint |
|--------|-----|----------|
| Arithmetic | Floating-point | Integer only |
| Speed | Slower | Faster |
| Accuracy | Round-off errors | Exact |
| Complexity | Simple | Slightly complex |

## Features of this Implementation
- Handles all 8 octants (all slopes and directions)
- Draws two symmetric lines (green and red) for demonstration
- Interactive user input for endpoints

## Usage
```
=== Midpoint Line Drawing Algorithm ===
Enter initial points (X1 Y1): -50 -30
Enter final points (X2 Y2): 50 30
```

## Sample Inputs to Try
| Start Point | End Point | Description |
|-------------|-----------|-------------|
| (-50, -30) | (50, 30) | Creates an "X" pattern |
| (0, 0) | (80, 20) | Gentle slope |
| (0, 0) | (20, 80) | Steep slope |

## Compilation
```bash
g++ midpoint_line.cpp -o midpoint_line -lopengl32 -lglu32 -lfreeglut
```
