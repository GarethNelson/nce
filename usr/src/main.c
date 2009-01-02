#include <nce.h>

void nce_glut_loop() {
     printf("NCE: Entering GLUT main loop\n");
     glutMainLoop();
}

static void glut_reshape(int w, int h) {
   if (nce_app_reshape == NULL) {
     glViewport(0, 0, w, h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(0, w, 0, h, -1, 1);
     glScalef(1, -1, 1);
     glTranslatef(0, -h, 0);
   } else {
     (*nce_app_reshape)(w,h);
   }
}

static void glut_display() {
     if (nce_app_redraw != NULL) {
        (*nce_app_redraw)();
     }
}

void nce_enable_glut(unsigned int w, unsigned int h) {
     glutInit(&gce_argc,gce_argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
     glutInitWindowSize(w,h);
     glutCreateWindow(APP_TITLE);
     glutDisplayFunc(glut_display);
     glutReshapeFunc(glut_reshape);
}

void nce_disable_glut() {
     glutDestroyWindow(1);
}

int main(int argc, char ** argv) {
    printf("NCE - Nelson's Crossplatform Environment\n");
    nce_argc=argc;
    nce_argv=argv;

    printf("Starting 3rd-party libs for %s:\n", APP_TITLE);
    
    printf("Setting up python runtime:\n");
    Py_Initialize();
    printf("Python %s\n",Py_GetVersion());

    printf("Setting up GLUT/OpenGL:\n");
    nce_app_redraw  = NULL;
    nce_app_reshape = NULL;

    printf("Switching control to app_main():\n");
    app_main(argc,argv);
}
