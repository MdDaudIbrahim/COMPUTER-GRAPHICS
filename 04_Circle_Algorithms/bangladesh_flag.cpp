/**
 * Bangladesh Flag using OpenGL
 * ============================
 * A practical application combining basic shapes:
 * - Rectangles for the flag and pole
 * - Filled circle for the red sun
 * - Triangle for the pole top
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

const float PI = 3.14159265359f;

/**
 * Draw a filled circle using triangles
 * 
 * @param cx, cy - Center coordinates
 * @param radius - Circle radius
 */
void drawFilledCircle(float cx, float cy, float radius) {
    int triangleAmount = 100;
    float twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);  // Center
        for (int i = 0; i <= triangleAmount; i++) {
            float angle = twicePi * i / triangleAmount;
            glVertex2f(cx + radius * cosf(angle),
                       cy + radius * sinf(angle));
        }
    glEnd();
}

/**
 * Display callback function
 * Draws the complete Bangladesh flag with pole
 */
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // ========== FLAG POLE - BOTTOM PART ==========
    glColor3f(0.1f, 0.1f, 0.1f);  // Dark gray/black
    glBegin(GL_POLYGON);
        glVertex2f(150, 100);   // Bottom-left
        glVertex2f(158, 100);   // Bottom-right
        glVertex2f(158, 200);   // Top-right
        glVertex2f(150, 200);   // Top-left
    glEnd();

    // ========== FLAG POLE - TOP PART ==========
    glColor3f(0.85f, 0.85f, 0.85f);  // Light gray/white
    glBegin(GL_POLYGON);
        glVertex2f(150, 200);
        glVertex2f(158, 200);
        glVertex2f(158, 350);
        glVertex2f(150, 350);
    glEnd();

    // ========== POLE TOP (Triangle) ==========
    glColor3f(0.2f, 0.2f, 0.2f);  // Dark gray
    glBegin(GL_TRIANGLES);
        glVertex2f(154, 365);   // Top point
        glVertex2f(145, 350);   // Bottom-left
        glVertex2f(163, 350);   // Bottom-right
    glEnd();

    // ========== GREEN RECTANGLE (Flag body) ==========
    glColor3f(0.0f, 0.4f, 0.25f);  // Bangladesh green
    glBegin(GL_POLYGON);
        glVertex2f(158, 200);   // Bottom-left (attached to pole)
        glVertex2f(450, 200);   // Bottom-right
        glVertex2f(450, 350);   // Top-right
        glVertex2f(158, 350);   // Top-left
    glEnd();

    // ========== RED CIRCLE (Sun) ==========
    // Positioned slightly left of center (as per actual flag design)
    glColor3f(0.94f, 0.16f, 0.16f);  // Bangladesh red
    drawFilledCircle(285, 275, 50);

    glFlush();
}

/**
 * Initialize OpenGL settings
 */
void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // White background (sky)
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

/**
 * Main function
 */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Bangladesh Flag - Computer Graphics Lab");

    glutDisplayFunc(display);
    myInit();
    glutMainLoop();

    return 0;
}
