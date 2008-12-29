#ifndef __GCE_H_
#define __GCE_H_

#ifdef WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <stdlib.h>
#include <GL/glut.h>
#include <python/Python.h>

//================== Global variables ===========================

int    gce_argc;
char **gce_argv;

//================== GLUT and OpenGL stuff ======================

// callbacks
void (*gce_app_redraw)(void);
void (*gce_app_reshape)(int w,int h);

// start the GLUT main loop - will never return, set your callbacks first or start a new thread!
void gce_glut_loop();

// set redraw callback

// enable/disable the GLUT output window
void gce_enable_glut(unsigned int w, unsigned int h);
void gce_disable_glut();


#endif
