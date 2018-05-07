#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    pid_t pid_h1, pid_h2, pid_h3;
    pid_t pid_n;
    static int *i;
    int status;

    i = mmap(NULL, sizeof *i, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    *i = 0;
    pid_h1 = fork();
    if (pid_h1 == 0) {
        ++*i;
        pid_n = fork();
        if (pid_n == 0) {
            printf("NIETO: i = %d\n", *i);
        }
        else {
            wait(&status);
            ++*i;
            printf("HIJO 1: i = %d\n", *i);
        }
    }
    else {
        wait(&status);
        pid_h2 = fork();
        if (pid_h2 == 0) {
            ++*i;
            printf("HIJO 2: i = %d\n", *i);
        }
        else {
            wait(&status);
            pid_h3 = fork();
            if (pid_h3 == 0) {
                ++*i;
                printf("HIJO 3: i = %d\n", *i);
            }
            else {
                wait(&status);
                ++*i;
                printf("PAPA: i = %d\n", *i);
            }
        }
    }
    return 0;
}