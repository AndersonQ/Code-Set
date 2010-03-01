
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


int main(){
  int i;
  struct timeval tempo_inicial, tempo_final;
  double total;

  //pega tempo inicial
  gettimeofday(&tempo_inicial, NULL);

  for(i=0; i<10000000; i++);

  //Fim da medicao do tempo.
  gettimeofday(&tempo_final, NULL);

  //total em microssegundos
  total = (tempo_final.tv_sec - tempo_inicial.tv_sec) * 1000000 + (tempo_final.tv_usec - tempo_inicial.tv_usec);;

  //imprime total em segundos
  printf("Tempo do relogio: %.9f milisegundos\n", total/1000);

  return 0;
}

