/**
 * DDA Line Drawing Algorithm
 * ==========================
 * The Digital Differential Analyzer (DDA) is a line drawing algorithm
 * that uses floating-point arithmetic to calculate intermediate points.
 * 
 * Algorithm Steps:
 * 1. Calculate dx = x2 - x1 and dy = y2 - y1
 * 2. Determine steps = max(|dx|, |dy|)
 * 3. Calculate increments: xInc = dx/steps, yInc = dy/steps
 * 4. Starting from (x1, y1), plot rounded coordinates
 * 5. Increment x and y by xInc and yInc respectively
 * 
 * Student ID: 22-49760-3
 * Course: Computer Graphics
 */

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

// Global variables for line endpoints (user input)
float x1_coord, y1_coord, x2_coord, y2_coord;

/**
 * Draw coordinate axes for reference
 */
void drawAxes() {
    glColor3ub(0, 0, 0);  // Black color
    glBegin(GL_LINES);
        // X-axis
        glVertex2i(-100, 0);
        glVertex2i(100, 0);
        // Y-axis
        glVertex2i(0, -100);
        glVertex2i(0, 100);
    glEnd();
}

/**
 * DDA Line Drawing Algorithm Implementation
 * 
 * @param x1, y1 - Starting point coordinates
 * @param x2, y2 - Ending point coordinates
 */
void drawLineDDA(float x1, float y1, float x2, float y2) {
    // Step 1: Calculate differences
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Step 2: Determine number of steps
    // Choose the larger of |dx| or |dy| to ensure no gaps
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    // Step 3: Calculate increment values
    float xInc = dx / steps;
    float yInc = dy / steps;

    // Step 4: Start from the initial point
    float x = x1;
    float y = y1;

    // Step 5: Plot points along the line
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2i(round(x), round(y));  // Round to nearest integer
        x += xInc;
        y += yInc;
    }
    glEnd();
}

/**
 * Display callback function
 */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw coordinate axes
    drawAxes();

    // Draw the line using DDA algorithm (Green color)
    glColor3ub(0, 255, 0);
    drawLineDDA(x1_coord, y1_coord, x2_coord, y2_coord);

    glFlush();
}

/**
 * Initialize OpenGL settings
 */
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
    glPointSize(3.0);                   // Point size for visibility
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);  // Coordinate system: -100 to 100
}

/**
 * Main function
 */
int main(int argc, char** argv) {
    // Get line endpoints from user
    cout << "=== DDA Line Drawing Algorithm ===" << endl;
    cout << "Enter starting point (x1 y1): ";
    cin >> x1_coord >> y1_coord;

    cout << "Enter ending point (x2 y2): ";
    cin >> x2_coord >> y2_coord;

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Drawing Algorithm - Lab 2");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
