/**
 * Midpoint Circle Drawing Algorithm
 * ==================================
 * An efficient algorithm for drawing circles using 8-way symmetry.
 * Uses only integer arithmetic for efficiency.
 * 
 * Algorithm:
 * 1. Start at (0, r) - top of the circle
 * 2. Initial decision parameter: p = 1 - r
 * 3. For each step:
 *    - If p < 0: Choose East pixel, p += 2x + 1
 *    - Else: Choose Southeast pixel, p += 2(x - y) + 1, y--
 *    - Plot 8 symmetric points
 * 4. Continue until x >= y
 * 
 * Student ID: 22-49760-3
 * Course: Computer Graphics
 */

#include <windows.h>
#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

/**
 * Plot 8 symmetric points for a circle
 * Exploits the 8-way symmetry of a circle
 * 
 * @param xc, yc - Center of the circle
 * @param x, y - Current calculated point offset
 */
void plot8Points(int xc, int yc, int x, int y) {
    glBegin(GL_POINTS);
        // Octant 1 and 2
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        // Octant 3 and 4
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        // Octant 5 and 6
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        // Octant 7 and 8
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
    glEnd();
}

/**
 * Midpoint Circle Algorithm Implementation
 * 
 * @param xc, yc - Center coordinates
 * @param radius - Radius of the circle
 */
void midpointCircle(int xc, int yc, int radius) {
    // Start at top of circle
    int x = 0;
    int y = radius;
    
    // Initial decision parameter
    int p = 1 - radius;

    // Plot first set of 8 symmetric points
    plot8Points(xc, yc, x, y);

    // Loop until x crosses y (we've covered the first octant)
    while (x < y) {
        x++;

        if (p < 0) {
            // Choose East pixel (E)
            // Midpoint is inside circle, stay at same y
            p = p + 2 * x + 1;
        } else {
            // Choose Southeast pixel (SE)
            // Midpoint is outside circle, move y down
            y--;
            p = p + 2 * (x - y) + 1;
        }
        
        // Plot 8 symmetric points for current position
        plot8Points(xc, yc, x, y);
    }
}

/**
 * Draw coordinate axes
 */
void drawAxes() {
    glColor3f(0.5f, 0.5f, 0.5f);  // Gray color

    // X-axis
    glBegin(GL_LINES);
        glVertex2i(-200, 0);
        glVertex2i(200, 0);
    glEnd();

    // Y-axis
    glBegin(GL_LINES);
        glVertex2i(0, -200);
        glVertex2i(0, 200);
    glEnd();
}

/**
 * Display callback function
 */
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw coordinate axes
    drawAxes();
    
    // Draw circle using Midpoint algorithm
    // Center at (-2, -2), radius = 50
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color
    midpointCircle(0, 0, 50);
    
    // Draw another circle for demonstration
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue color
    midpointCircle(60, 60, 30);

    glFlush();
}

/**
 * Initialize OpenGL settings
 */
void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // White background
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}

/**
 * Main function
 */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint Circle Algorithm - Lab 4");

    glutDisplayFunc(display);
    myInit();
    glutMainLoop();

    return 0;
}
