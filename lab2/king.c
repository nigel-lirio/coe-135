#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h> 
#include <signal.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if(argc == 2){
        
        do{
            int trials = 0, complete = 0, fif_io ;
            char* code = malloc(4 * sizeof(char));
            printf("Enter the number of trials per contestant: ");
            scanf("%d", &trials);
            printf("Enter the secret code: ");
            scanf("%s", code);
            fif_io = open(argv[1], O_RDONLY);
            do{
                char* pid = malloc(9 * sizeof(char));
                char* inp = malloc(4 * sizeof(char));
                read(fif_io,pid,sizeof(pid));
                printf("PID: %s \n", pid);
                for (int i = 0; i < trials; i++)
                {
                    printf("TRY: ");
                    
                    read(fif_io, inp, sizeof(inp));
                    puts(inp);
                    
                    if (strcmp(inp, code) == 0)
                    {
                        complete = 1;
                        close(fif_io);
                        break;
                    }
                    
                    

                }
                free(inp);
                kill(atoi(pid), SIGKILL);
                free(pid);
            }while(complete == 0);
            free(code);
        }while(1);

    }
    else{
        printf("Invalid arguments");
    }
    
    return 0;
}