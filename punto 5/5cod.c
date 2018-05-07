#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
  int pid;
  int numHijos = 5;
  int numProceso;
  int status;
  for(numProceso = 0; numProceso < numHijos; numProceso++) {
      pid = fork();
      if (pid == -1) {
          // Imprimir algún mensaje de error
      } else if(pid == 0) {
          break;
      }
  }
  if (pid == 0) {
      // Lógica del hijo
      printf("Soy el hijo #%d\n", numProceso);
  }
  else {
      wait(&status);
      wait(&status);
      wait(&status);
      wait(&status);
      wait(&status);
      printf("Soy un padre perezoso\n");
  }
}