#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include "main.exe.h"
#include "glut32.dll.h"

int main(int argc, char **argv) {
    printf("Extracting ");

    printf(" glut32.dll ");
    FILE *glut_file = fopen("glut32.dll","w");
    if (glut_file == NULL) {
       printf(strerror(errno));
       return 1;
    }
    int written = fwrite((const void*)embedded_glut32_dll, 1, glut32_dll_len, glut_file);
    printf("(%d bytes written) ", written);
    fclose(glut_file);

    printf(" main.exe ");
    FILE *exe_file = fopen("main.exe","w");
    if (exe_file == NULL) {
       printf(strerror(errno));
       return 1;
    }
    written = fwrite((const void*)embedded_main_exe, 1, main_exe_len, exe_file);
    printf("(%d bytes written) ",written);
    fclose(exe_file);
    
    printf("OK!\n");
    printf("Starting application:\n");
    if(system("main.exe") != 0) printf(strerror(errno));
}
