#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  int i;
  int status;
  printf("the arguments of the command line: ");
  for (i=1; i<argc; i++){
    printf("%s ", argv[i]);
  }
  printf("\n");
  pid_t pid = fork();
  if(pid ==0){
    execvp(argv[1], argv+1);
  }
  else{
    wait(&status);
  }
  printf("exit status: %d\n", WEXITSTATUS(status));
}

