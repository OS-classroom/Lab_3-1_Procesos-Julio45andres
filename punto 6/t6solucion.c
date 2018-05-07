#include <stdio.h>
#include <unistd.h>

void printc(char *out);

int main()
{
    pid_t pid;
    printc("Hola ");
    pid = fork();
    if (pid == 0) {
        printc("Mundo");
    }
    else{
        pid = fork();
        if(pid == 0)
            printc("!\n");
    }
    return 0;
}

// Función printclean, imprime y limpia en el stdout.
void printc(char *out){
    printf("%s", out);
    fflush(stdout);
}