#include "run_program.h"
#include <unistd.h>     /*for fork*/
#include <string.h>     /*for memcpy*/
#include <stdlib.h>     /*for exit*/
#include <sys/wait.h>   /*for waitpid*/

#define ERROR_CODE 127

int run_program(char *file_path, char *arguments[])
{
    int status;
    int pid;

    if ((file_path == NULL) || (arguments == NULL)){
        return ERROR_CODE;
    }

    pid = fork();
    
    if (pid == -1) {    //process creates an error
        return ERROR_CODE;    
    } else if (pid == 0) { //child process

        int num = 0;
        char **narguments;

        /* The first argument that we provide execvp() should contain the programm that we want to execute.
        We therefore have to copy the provided argument list and prepend it with file_path*/

        while (arguments[num++] != NULL);
        
        /*Speicher allozieren für narguments. Da file_path mit in narguments reinkommt, wird das narguments 1 Feld größer
        --> malloc(size(c) * num + 1)*/

        narguments = (char**)malloc((sizeof(char*)) * (num + 1));

        if (narguments == NULL) {
            return ERROR_CODE;
        }

        /*narguments wird deklariert bei dem das erste element der file_path ist
        und das 2. Element die restlichen Argumente speichert
        Hier wird mittels memcpy alles von den Übergabeparametern in dem 2. Element gespeichert*/
        narguments[0] = file_path;
        memcpy(&narguments[1], arguments, sizeof(char*) * num);

        /*execvp() replaces current process with new process. It has the advantage of searching for the file
        in the PATH variable. Other execs will search in the path where program is executed*/    
        execvp(narguments[0], narguments);
        
        /*Das wird nur erreicht, wenn exit failed. Andererseits wird das Ausführen in der Main des neues Programms fortgeführt*/
        exit(ERROR_CODE);

    } else {
        if (waitpid(pid, &status, 0) == -1){
            return ERROR_CODE;
        }

        return (WIFEXITED(status)) ? WIFEXITED(status) : ERROR_CODE;
    }
}
