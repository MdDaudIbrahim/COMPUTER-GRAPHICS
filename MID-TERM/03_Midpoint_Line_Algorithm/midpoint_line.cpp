/**
 * Midpoint Line Drawing Algorithm (Bresenham's Algorithm)
 * =======================================================
 * An efficient line drawing algorithm that uses only integer arithmetic.
 * More efficient than DDA as it avoids floating-point calculations.
 * 
 * Algorithm (for gentle slope, dx > dy):
 * 1. Calculate: d = 2*dy - dx (initial decision parameter)
 * 2. For each x from x1 to x2:
 *    - Plot (x, y)
 *    - If d < 0: d = d + 2*dy (choose East pixel)
 *    - Else: d = d + 2*(dy - dx), y++ (choose Northeast pixel)
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

// Global variables for line endpoints
int X1, Y1, X2, Y2;

/**
 * Draw coordinate axes for reference
 */
void drawAxes() {
    glColor3f(0.0, 0.0, 0.0);  // Black
    glLineWidth(2.0);
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
 * Midpoint Line Drawing Algorithm Implementation
 * Handles all slopes and directions
 * 
 * @param x1, y1 - Starting point
 * @param x2, y2 - Ending point
 * @param r, g, b - RGB color values
 */
void drawLineWithMidpoint(int x1, int y1, int x2, int y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);

    // Calculate absolute differences
    int deltaX = abs(x2 - x1);
    int deltaY = abs(y2 - y1);
    
    // Current position
    int xPos = x1;
    int yPos = y1;

    // Determine direction of increment
    int xIncrement = (x1 < x2) ? 1 : -1;
    int yIncrement = (y1 < y2) ? 1 : -1;

    // Case 1: Gentle slope (|slope| <= 1)
    if (deltaX >= deltaY) {
        // Initial decision parameter
        int decision = 2 * deltaY - deltaX;
        int incrementE = 2 * deltaY;           // East increment
        int incrementNE = 2 * (deltaY - deltaX); // Northeast increment

        // Plot initial point
        glVertex2i(xPos, yPos);

        // Iterate through all x values
        while (xPos != x2) {
            if (decision < 0) {
                // Choose East pixel
                decision += incrementE;
            } else {
                // Choose Northeast pixel
                decision += incrementNE;
                yPos += yIncrement;
            }
            xPos += xIncrement;
            glVertex2i(xPos, yPos);
        }
    }
    // Case 2: Steep slope (|slope| > 1)
    else {
        // Initial decision parameter (swap roles of x and y)
        int decision = 2 * deltaX - deltaY;
        int incrementE = 2 * deltaX;
        int incrementNE = 2 * (deltaX - deltaY);

        // Plot initial point
        glVertex2i(xPos, yPos);

        // Iterate through all y values
        while (yPos != y2) {
            if (decision < 0) {
                decision += incrementE;
            } else {
                decision += incrementNE;
                xPos += xIncrement;
            }
            yPos += yIncrement;
            glVertex2i(xPos, yPos);
        }
    }

    glEnd();
}

/**
 * Display callback function
 * Draws two symmetric lines to demonstrate the algorithm
 */
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw coordinate axes
    drawAxes();

    // Draw first line - Green (from user input)
    drawLineWithMidpoint(X1, Y1, X2, Y2, 0.0, 1.0, 0.0);

    // Draw second line - Red (symmetric/reflected)
    drawLineWithMidpoint(X1, Y2, X2, Y1, 1.0, 0.0, 0.0);

    glFlush();
}

/**
 * Initialize OpenGL settings
 */
void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // White background
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

/**
 * Main function
 */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint Line Algorithm - Lab 3");

    // Get line endpoints from user
    cout << "=== Midpoint Line Drawing Algorithm ===" << endl;
    cout << "Enter initial points (X1 Y1): ";
    cin >> X1 >> Y1;
    cout << "Enter final points (X2 Y2): ";
    cin >> X2 >> Y2;

    glutDisplayFunc(display);
    myInit();
    glutMainLoop();

    return 0;
}
