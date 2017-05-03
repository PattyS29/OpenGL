#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables
double rotate_x=0;
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat light_position[] = {0.0, 0.2, -0.9, 0.0};
void display()
{

    // materiales globales
    GLfloat mat_ambient[] = { 0.1745f, 0.01175f, 0.01175f,1.0f };
    GLfloat mat_diffuse[] = { 0.61424f, 0.04136f, 0.04136f, 1.0f };
    GLfloat mat_specular[] = { 0.727811f, 0.626959f, 0.626959f, 1.0f };
    GLfloat shine[] = {27.8974f};
    //Ruby


    glClearColor(0.60,0.40,0.70,0.5);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
  // Rotacion de -5 grados en torno al eje x
    glRotated(-5, 1.0, 0.0, 0.0);
  // Rotacion de 20 grados en torno al eje y
    glRotated(20.0, 0.0, 1.0, 0.0);
   //setMaterial
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    glPushMatrix();
    
    mat_ambient[0] = 0.0;
    mat_ambient[1] =0.0;
    mat_ambient[2] =0.0,1.0f;
    mat_diffuse[0] =0.5;
    mat_diffuse[1] =0.0;
    mat_diffuse[2] =0.0, 1.0f;
    mat_specular[0] =0.7;
    mat_specular[1] =0.6;
    mat_specular[2] =0.6, 1.0f ;
    shine[0] = 0.25f;
    //primer cubo color azul base
    glRotatef(0.0,0.1,0.1,0.0); 
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0.0f, -0.7f, 0.0f);
    glutSolidCube(0.2);
    glPopMatrix();
    glPushMatrix();
    //rectangulo vertical color rojo
    for (GLfloat i=-0.6; i<=0.2; i+=0.01)
    {
        glColor3f(1.0, 0.0, 0.0);
        glTranslated(0.0f, i, 0.0f);
        glutSolidCube(0.1);
        glPopMatrix();
        glPushMatrix();
    }
   //rectangulo de arriba color azul
    for (GLfloat j=0.0; j<=0.6; j+=0.01)
    {
        glColor3f(0.0, 0.0, 1.0);
        glRotatef (rotate_x, 0.0 , 0.1 , 0.0 );
        glTranslated(j, 0.3 , 0.0f);
        glutSolidCube(0.1);
        glPopMatrix();
        glPushMatrix();
    }
    //rectangulo vertical color azul
    for (GLfloat k=-0.1; k<=0.3; k+=0.01)
    {
        glColor3f(0.0, 0.0, 1.0);
        glRotatef (rotate_x, 0.0 , 0.1 , 0.0 );
        glTranslated(0.6f, k, 0.0f);
        glutSolidCube(0.1);
        glPopMatrix();
        glPushMatrix();
    }
    //Cable
    for (GLfloat L=-0.5; L<=0.0; L+=0.01)
    {
        glColor3f(0.25, 0.25, 0.25);
        glRotatef (rotate_x, 0.0 , 0.1 , 0.0 );
        glTranslatef (X, Y, Z);
        glTranslated(0.6f, L, 0.0f);
        glutSolidCube(0.01);
        glPopMatrix();
        glPushMatrix();
    } 
    //Cubo Iman
    glColor3f(0.0, 0.0, 0.0);
    glRotatef (rotate_x, 0.0 , 0.1 , 0.0 );
    glTranslatef (X, Y, Z);
    glTranslated(0.6f, -0.5f, 0.0f);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
     //Cubo  Color amarillo
    glTranslated(0.6f, -0.7f, 0.0f);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    //Cubo color rojo
    glColor3f(1.0, 0.0, 0.0);
    glTranslated(-0.6f, -0.7f, 0.0f);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    //Cubo  Color Verde
    glColor3f(0.0, 1.0, 0.0);
    glTranslated(0.0f, -0.5f, 0.6f);
    glutSolidCube(0.1);
    glPopMatrix();
    glPushMatrix();
    glEnd();
    glFlush();
    glutSwapBuffers();

}
void  specialKeys ( int key, int x, int y)
{
    //Flecha arriba: Rotación en eje X positivo 7 grados
    if (key == GLUT_KEY_RIGHT)
            rotate_x +=7; 
    //Flecha abajo: Rotación en eje X negativo 7 grados
    if (key == GLUT_KEY_LEFT)
            rotate_x -=7;
    //arriba Flecha: 0.01f sube en Y
    if (key== GLUT_KEY_UP)
            if (Y <= 0.25 )
            {
                Y +=0.01f ;
            }
    //abajo Flecha: 0.01f baja en Y
    if (key== GLUT_KEY_DOWN)
            if (Y >=-0.1)
            {
                Y -=0.01f ; 
            }
    //Solicitar Actualización de Visualizacion
    glutPostRedisplay ();
}

int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("parcial#2");

    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}