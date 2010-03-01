/*

Programa tempo.c - exemplo de utilização da chamada fork(); é uma versão
modificada do exemplo da seção 1.5.2 (pags. 9-10) da apostila de
sistemas operacionais (Magalhães, Cardozo, Faina).

Historico: criado por Magalhaes, Cardozo
Modificado: Mauro Aurelio
            Roberto Lotufo 6nov96

Compilacao: gcc tempo.c -o tempo

Execucao: tempo <comando>
          onde <comando> pode ser ls por exemplo

Sugestao de Modificacoes:
1. Retire a chamada wait(NULL) e observe o comportamento
2. Faca com que cada processo imprima o seu pid
   o pid 'e obtido chamando-se getpid()
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>

main(int argc, char *argv[])
{
  int pid;
  struct timeval tv1, tv2;
  double t1, t2;

  if(argc != 2)
  {
    printf("Uso: tempo algum_comando\n");
    exit(1);
  }

  pid = fork();                                /* fork */
  if(pid == 0) {
    printf("\nProcesso filho vai executar %s agora.\n",argv[1]);
    gettimeofday(&tv1, NULL);   /* processo pai continua ... */
    t1 = (double)(tv1.tv_sec) + (double)(tv1.tv_usec)/ 1000000.00;
    system(argv[1]);             /* processo filho executa comando */
    gettimeofday(&tv2, NULL);
    t2 = (double)(tv2.tv_sec) + (double)(tv2.tv_usec)/ 1000000.00;
    printf("\nExecucao de %s terminou agora.\n",argv[1]);
    printf("\nO tempo de execucao de %s por filho foi: %lf\n", 
	   argv[1], (t2 - t1));
  }
  else{  
    gettimeofday(&tv1, NULL);   /* processo pai continua ... */
    t1 = (double)(tv1.tv_sec) + (double)(tv1.tv_usec)/ 1000000.00;
    /*    wait(NULL); */            /* sincroniza com o termino do filho */
    gettimeofday(&tv2, NULL);
    t2 = (double)(tv2.tv_sec) + (double)(tv2.tv_usec)/ 1000000.00;
    printf("\nO tempo de execucao de processo pai foi: %lf\n",(t2 - t1));
  }
}






