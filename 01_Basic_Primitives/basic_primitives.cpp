/**
 * Basic OpenGL Primitives
 * =======================
 * This program demonstrates fundamental OpenGL drawing primitives:
 * - Points (GL_POINTS)
 * - Lines (GL_LINES)
 * - Triangles (GL_TRIANGLES)
 * - Quadrilaterals (GL_QUADS)
 * - Polygons (GL_POLYGON)
 * 
 * Student ID: 22-49760-3
 * Course: Computer Graphics
 */

#include <windows.h>
#include <GL/glut.h>

/**
 * Display callback function
 * Draws various primitives on the screen
 */
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // White background
    glClear(GL_COLOR_BUFFER_BIT);

    // ========== COORDINATE AXES ==========
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);  // Black color
        // X-Axis
        glVertex2f(-1, 0);
        glVertex2f(1, 0);
        // Y-Axis
        glVertex2f(0, -1);
        glVertex2f(0, 1);
    glEnd();

    // ========== POINTS ==========
    glPointSize(10);
    glBegin(GL_POINTS);
        // Blue point at (0.5, 0.5)
        glColor3f(0, 0, 1);
        glVertex2f(0.5, 0.5);
        
        // Yellow point at origin
        glColor3f(1, 1, 0);
        glVertex2f(0, 0);
    glEnd();

    // ========== GREEN TRIANGLE (Bottom-left quadrant) ==========
    glBegin(GL_TRIANGLES);
        glColor3f(0, 1, 0);  // Green
        glVertex2f(-0.6, -0.2);
        glVertex2f(-0.6, -0.5);
        glVertex2f(-0.3, -0.5);
    glEnd();

    // ========== RED SQUARE (Top-left quadrant) ==========
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);  // Red
        glVertex2f(-0.9, 0.6);   // Top-left
        glVertex2f(-0.5, 0.6);   // Top-right
        glVertex2f(-0.5, 0.9);   // Bottom-right
        glVertex2f(-0.9, 0.9);   // Bottom-left
    glEnd();

    // ========== CYAN RECTANGLE ==========
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.8, 1.0);  // Cyan
        glVertex2f(-0.4, 0.1);   // Bottom-left
        glVertex2f(-0.15, 0.1);  // Bottom-right
        glVertex2f(-0.15, 0.75); // Top-right
        glVertex2f(-0.4, 0.75);  // Top-left
    glEnd();

    // ========== MAGENTA PENTAGON (Bottom-right quadrant) ==========
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 1.0);  // Magenta
        glVertex2f(0.65, -0.25);   // Top vertex
        glVertex2f(0.85, -0.4);    // Top-right
        glVertex2f(0.77, -0.65);   // Bottom-right
        glVertex2f(0.53, -0.65);   // Bottom-left
        glVertex2f(0.45, -0.4);    // Top-left
    glEnd();

    glFlush();
}

/**
 * Main function - Entry point of the program
 */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Basic OpenGL Primitives - Computer Graphics Lab 1");
    glutInitWindowSize(640, 640);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
