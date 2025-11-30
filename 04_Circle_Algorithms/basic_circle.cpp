/**
 * Circle Drawing using Trigonometric Functions
 * =============================================
 * This approach uses sin() and cos() functions to draw circles.
 * Less efficient than Midpoint algorithm but easier to understand.
 * 
 * Two methods demonstrated:
 * 1. Filled Circle - using GL_TRIANGLE_FAN
 * 2. Hollow Circle - using GL_LINE_LOOP
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
 * Uses GL_TRIANGLE_FAN for efficient filling
 * 
 * @param cx, cy - Center coordinates
 * @param radius - Circle radius
 * @param segments - Number of triangles (higher = smoother)
 */
void drawFilledCircle(float cx, float cy, float radius, int segments = 100) {
    float twicePi = 2.0f * PI;
    
    glBegin(GL_TRIANGLE_FAN);
        // Center point of the fan
        glVertex2f(cx, cy);
        
        // Vertices around the circle
        for (int i = 0; i <= segments; i++) {
            float angle = twicePi * i / segments;
            float x = radius * cosf(angle);
            float y = radius * sinf(angle);
            glVertex2f(cx + x, cy + y);
        }
    glEnd();
}

/**
 * Draw a hollow circle (outline only)
 * Uses GL_LINE_LOOP to connect points
 * 
 * @param cx, cy - Center coordinates
 * @param radius - Circle radius
 * @param segments - Number of line segments (higher = smoother)
 */
void drawHollowCircle(float cx, float cy, float radius, int segments = 100) {
    float twicePi = 2.0f * PI;
    
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= segments; i++) {
            float angle = twicePi * i / segments;
            float x = radius * cosf(angle);
            float y = radius * sinf(angle);
            glVertex2f(cx + x, cy + y);
        }
    glEnd();
}

/**
 * Draw coordinate axes
 */
void drawAxes() {
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
        // X-axis
        glVertex2f(0, 240);
        glVertex2f(640, 240);
        // Y-axis
        glVertex2f(320, 0);
        glVertex2f(320, 480);
    glEnd();
}

/**
 * Display callback function
 */
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawAxes();
    
    // Draw filled circles
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    drawFilledCircle(200, 300, 50);
    
    glColor3f(0.0f, 1.0f, 0.0f);  // Green
    drawFilledCircle(440, 300, 40);
    
    // Draw hollow circles
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    glLineWidth(2.0);
    drawHollowCircle(320, 150, 60);
    
    glColor3f(1.0f, 0.5f, 0.0f);  // Orange
    drawHollowCircle(200, 300, 70);  // Outline around red circle

    glFlush();
}

/**
 * Initialize OpenGL settings
 */
void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
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
    glutCreateWindow("Trigonometric Circle Drawing");

    glutDisplayFunc(display);
    myInit();
    glutMainLoop();

    return 0;
}
