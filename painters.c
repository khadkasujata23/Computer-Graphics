#include <GL/freeglut.h>

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Back object (draw first)
    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_QUADS);
        glVertex2f(-0.5, 0.3);
        glVertex2f(0.3, 0.3);
        glVertex2f(0.3, -0.3);
        glVertex2f(-0.5, -0.3);
    glEnd();

    // Middle object
    glColor3f(0.0, 1.0, 0.0); // Green
    glBegin(GL_QUADS);
        glVertex2f(-0.2, 0.1);
        glVertex2f(0.6, 0.1);
        glVertex2f(0.6, -0.5);
        glVertex2f(-0.2, -0.5);
    glEnd();

    // Front object (draw last)
    glColor3f(0.0, 0.0, 1.0); // Blue
    glBegin(GL_QUADS);
        glVertex2f(0.0, -0.1);
        glVertex2f(0.8, -0.1);
        glVertex2f(0.8, -0.7);
        glVertex2f(0.0, -0.7);
    glEnd();

    glFlush();
}

// Initialization
void init() {
    glClearColor(0.1, 0.1, 0.1, 1.0); // Background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Painter Algorithm - FreeGLUT");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}