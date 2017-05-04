#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex3f(-5.0f,0.0f,0.0f);
    glVertex3f(5.0f,0.0f,0.0f);

    glVertex3f(0.0f,-5.0f,0.0f);
    glVertex3f(0.0f,5.0f,0.0f);

    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.0f, 0.0f); //para el rectangulo 
    glVertex3f(0.95f,0.5f,0.0f);
    glVertex3f(0.95f,-0.5f,0.0f);
    glVertex3f(-0.95f,-0.5f,0.0f);
    glVertex3f(-0.95f,0.5f,0.0f);
    glEnd();
    glBegin(GL_LINE_STRIP); //para la casita 
    glVertex3f(2.0f,2.0f,0.0f);
    glVertex3f(2.0f,-2.0f,0.0f);
    glVertex3f(-2.0f,-2.0f,0.0f);
    glVertex3f(-2.0f,2.0f,0.0f);
    glVertex3f(0.0f,5.0f,0.0f);
    glVertex3f(2.0f,2.0f,0.0f);
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Cuadrado-Rectangulo");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}