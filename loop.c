#include<stdio.h>
#include<time.h>
#include<signal.h>
#include<stdlib.h>

void sigint_handler( int signum ){
 printf("Przechwycony sygnal: %i \n", signum);
 exit(signum);
}


void sigalrm_handler(int signum){
 }


void sigusr1_handler(int signum){
 printf("Otrzymano sygnal nr %i \n", signum);
}


void sigusr2_handler(int signum){
}

void sigterm_handler(){}


int main(){

 int i = 1;
 struct timespec t;

 printf("Working...\n");
 t.tv_sec = 2;
 t.tv_nsec = 0;


 signal(SIGINT, sigint_handler);
 //signal(SIGALRM, sigalrm_handler);
 signal(SIGTERM, sigterm_handler);
 signal(SIGUSR1, sigusr1_handler);
 signal(SIGUSR2, sigusr2_handler); 

 while( 1 ){
   ++i;
   printf("Iteracja: %i\n", i);
  
   if( i % 10 )
     signal(SIGALRM, SIG_IGN);
   else{
     printf("Mozna otrzymac sygnal SIGALRM\n");
     signal(SIGALRM, SIG_DFL);
   }

   nanosleep(&t,0);
 }


 return 0;
}
