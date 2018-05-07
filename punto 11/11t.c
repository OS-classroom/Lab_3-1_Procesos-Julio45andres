#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef void (*twointpfunction)(char *, int, int);
void for_interval(char *msg, int i, int j);

int main () {
    int i;
    int numHijos = 3;
    pid_t pid;
    int status;
    char msg[10];
    twointpfunction forij = &for_interval;
    for (i = 0; i < numHijos; i++) {
        pid = fork();
        if (pid == -1) {
            /* Error */
            printf("No fue posible crear un hijo\n");
            return -1;
        }
        if (pid == 0) {
            //printf("Soy el hijo #%d con PID: %d\n",i+1, getpid());
            switch(i+1){
                case 1: 
                    snprintf(msg, 10, "Hijo %d: ", i+1);
                    (*forij)(msg, 1, 3);
                    break;
            }
            exit(0);
        }
        else{ //El padre espera al hijo antes de hacer otro fork()
            wait(&status);
        }
    }
    return 0;
}

void for_interval(char *msg, int i, int j){
    for(int k = i; k <= j; k++){
        printf("%s%d\n", msg, factorial(i));
    }
}

int factorial(int x){
    if(x == 0) return 0;
    if(x == 1) return x;
    return x*factorial(x-1);
}
