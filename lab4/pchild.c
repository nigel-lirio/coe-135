#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    __pid_t run = fork();
    if (run == 0){
        printf("CHILD PID: %d\n", getpid());
        exit(0);
    }
    else{
        wait(NULL);
        printf("PARENT PID: %d\n", getpid());
    }
    wait(NULL);
    execv("./hello", NULL);
}