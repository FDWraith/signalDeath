#include <stdio.h>
#include <stdlib.h>

#include <signal.h>

static void sighandler(int SIG){
  if( SIG == SIGINT ){
    printf("Exiting Due to SIGINT\n");
    exit();
  }else if( SIG == SIGUSR1 ){
    printf("Parent PID: %d\n", getppid());
  }
  
}

int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1) {
    printf("Current PID: %d\n", getpid());
    sleep(1);
  }
  
}
