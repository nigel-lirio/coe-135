#include <syscall.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    __pid_t pid;
    int rv;

    pid = fork();
    
}