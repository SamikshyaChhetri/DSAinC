#include<GLUT/glut.h>
#include<stdio.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glRectf(50, 40, 190, 80); // Draw a red rectangle
    
    glColor3f(0.0, 0.0, 1.0); // Set color to blue
    glBegin(GL_TRIANGLE_FAN); // Begin drawing a filled circle
    glVertex2f(120, 270);     // Center of the circle
    for (int i = 0; i <= 360; i++) {
        float angle = 3.1416 * i / 180.0;
        float x = 120 + 30 * cos(angle);
        float y = 270 + 30 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd(); // End drawing the circle

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Shapes");
    glutInitWindowSize(400, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

