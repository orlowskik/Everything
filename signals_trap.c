#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sigterm_handler(int signum ){
  printf("\nKoniec programu . . . sygnal nr: %i\n", signum);
  exit(signum);
}

void sigalrm_handler(int signum){
  printf("\nJestem niesmiertelny . . . sygnal nr: %i\n", signum);
}

void sigusr1_handler(){}

int main(){
  struct timespec t;
  int  i = 1;
  t.tv_sec  = 1;
  t.tv_nsec = 0 ;

  signal(SIGTERM, sigterm_handler);
  signal(SIGALRM,sigalrm_handler);
  signal(SIGUSR1,sigusr1_handler); 

  while(i){
   ++i;
  printf("%i",i);
  nanosleep( &t, 0);

  if(i%5){
   signal(SIGINT,SIG_IGN);
    }
   else{
    printf("Mozna zakonczyc\n");
    signal(SIGINT,SIG_DFL);
    }
   }

  return 0;

}
