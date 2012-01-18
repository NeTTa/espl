#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MSGSIZE  1024

int main(int argc, char* argv[]){
  int i;
  int status;
  printf("the arguments of the command line: ");
  for (i=1; i<argc; i++){
    printf("%s ", argv[i]);
  }
  printf("\n");
  pid_t pid = fork(); //split to father and child
  
  int p[2];
  
  
  
  if(pipe(p) == -1)
  {    perror("pipe call error");
       exit(1);
  }
  
  if(pid ==0){ //child execution
    //first close the read end of the pipe
    close (1); //dup2 closes 1 by itself
    dup2(p[1], 1);
    close(p[1]);
    
    //child action
    execvp(argv[1], argv+1);
    
    //write down pipe
    //write( p[1], , MSGSIZE);
    //File* fd1 = fdopen(p[1], w);
  }
  else{ //parent execution
    //first close the write end of the pipe
    close (0); //dup2 closes 0 by itself
    dup2(p[0], 0);
    close([0]);
    
    
    //read pipe
    //read(p[0], p[1], MSGSIZE);
    File* fd0 = fdopen(p[0], r);
    int i = 1;
    while (fgets(fd0)){
      printf("%d: %", i, fgets(fd0))
      i++;
    }
    wait(&status);
  }
  printf("exit status: %d\n", WEXITSTATUS(status));
}