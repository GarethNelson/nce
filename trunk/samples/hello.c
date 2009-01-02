#include <nce.h>

void redraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
      glColor3f(0.0, 0.0, 1.0);
      glVertex2i(0, 0);
      glColor3f(0.0, 1.0, 0.0);
      glVertex2i(200, 200);
      glColor3f(1.0, 0.0, 0.0);
      glVertex2i(20, 200);
    glEnd();
    glutSwapBuffers();
}

int app_main(int argc, char ** argv) {
    printf("hello.c speaking here!\n");
    
    printf("i'm going to create a new window and draw a triangle!\n");
    nce_app_redraw = &redraw;
    nce_enable_glut(1024,768);
    printf("GLUT enabled, entering loop...\n");
    nce_glut_loop();
    return 0;
}
