#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc == 2)
    {
        /* code */
        mkfifo(argv[1], 0666);
        while (1)
        {
            printf("PARENT PID: %d \n", getpid());
            if (fork() == 0)
            {
                printf("CHILD: %d \n", getpid());
                int fifo_io = open(argv[1], O_WRONLY);
                char* z = malloc(9 * sizeof(char));
                sprintf(z, "%d", getpid());
                write(fifo_io,z, sizeof(z));
                free(z);
                while (1)
                {
                    char* x = malloc(4 * sizeof(char));
                    scanf("%s", x);
                    write(fifo_io,x, sizeof(x));
                    free(x);
                }
                
            }
            
            wait(NULL);
            
        }
        
    }
    
}