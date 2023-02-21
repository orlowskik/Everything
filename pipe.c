#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>


#define BUFSIZE 1024


int main(int argc, char **argv){


  int pipe_fd[2], count, status;
  char buff[BUFSIZE];
  char* c; 
  FILE* file;

  if(argc < 2){
    printf("Brak podanego pliku\n");
    exit(-1);
  }
  
  file = fopen(argv[1], "r");
  pipe(pipe_fd);

  if(fork() != 0){
    while(fscanf(file,"%s", c)!=EOF)
       write(pipe_fd[1], c , strlen(c));
    exit(0);
  }
  else{
    close(pipe_fd[1]);
    while((count=read(pipe_fd[0], buff, BUFSIZE)) > 0 ){
       write(1,"#",1);
       write(1,buff,count);
       write(1,"#\n",1);
    }
   wait(&status);
   return(status);
  }
}
