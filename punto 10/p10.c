#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

void printproc(char *process);

int main(int argc, char *argv[]) {
    //pid_t pid_p1, pid_p2, pid_p3, pid_p4, pid_p5;
   // int status_p2, status_p3, status_p4, status_p5;
    pid_t pid, ppid;
    int status;
    char tree[20];


    printproc("Padre P0");
    ppid = getpid();
    pid = fork();
    if(pid < 0){
        printf("El fork ha fallado.\n");
        exit(-1);
    }
    if(pid == 0){
        //El hijo p2 de p1
        printproc("Hijo P2");
    }
    else{
        wait(&status);
        
        pid = fork();
        if(pid < 0){
            printf("El fork ha fallado.\n");
            exit(-1);
        }
        if(pid == 0){
            //El hijo p3 de p1
            printproc("Hijo P3");

            pid = fork();
            if(pid < 0){
                printf("El fork ha fallado.\n");
                exit(-1);
            }
            if(pid == 0){
                //El hijo p4 de p3
                printproc("Hijo P4");
            }
            else{
                pid = fork();
                if(pid < 0){
                    printf("El fork ha fallado.\n");
                    exit(-1);
                }
                if(pid == 0){
                    //El hijo p5 de p3
                    printproc("Hijo P5");
                }
                else{
                    printf("\n");
                    snprintf(tree, 20, "pstree %d", ppid);
                    system(tree);
                    wait(&status);
                    wait(&status);
                }
            }
        }
        else{
            wait(&status);
            wait(&status);
        }
    }
    return 0;
}

void printproc(char *process){
    printf("\n%s: Mi PID %d\n", process,(int)getpid());
    printf("%s: PID de mi padre %d\n", process, (int)getppid());
}