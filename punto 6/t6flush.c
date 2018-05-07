#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("Hola ");
    fflush(stdout);
    fork();
    printf("Mundo");
    fflush(stdout);
    fork();
    printf("!t6");
    fflush(stdout);
}