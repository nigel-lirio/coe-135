#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void process1(int *x) {
    *x = 1; 
}
void process2() {
    
}

int data = 0;
int main() {
    pid_t pid = fork();
    if(pid > 0){
        wait(NULL);
        process1(&data);
    }
    printf("data = %d\n", data);
    return 0;
}