#ifndef __NCE_H_
#define __NCE_H_

#ifdef WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <stdlib.h>
#include <GL/glut.h>
#include <python/Python.h>

//================== Global variables ===========================

int    nce_argc;
char **nce_argv;

//================== GLUT and OpenGL stuff ======================

// callbacks
void (*nce_app_redraw)(void);
void (*nce_app_reshape)(int w,int h);

// start the GLUT main loop - will never return, set your callbacks first or start a new thread!
void nce_glut_loop();

// set redraw callback

// enable/disable the GLUT output window
void nce_enable_glut(unsigned int w, unsigned int h);
void nce_disable_glut();


#endif
