#define _POSIX_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <signal.h>
int time_out = -1, totalq = 0, totalc = 0, d1 = 0, d2 = 0, sum = 0, inp = -1;
void alarm_handler(int sig){
    totalq++;
    d1 = rand() % 10;
    d2 = rand() % 10;
    alarm(3);
}
int main(){
    struct sigaction signalS;
    memset(&signalS,0,sizeof signalS);
    signalS.sa_handler = alarm_handler;
    sigaction(SIGALRM, &signalS, NULL);
    totalq++;
    d1 = rand() % 10;
    d2 = rand() % 10;
    sum = d1 + d2;
    alarm(3);
    while (1)
    {
        sum = d1 + d2;
        if(time_out == 0){
            printf("TIMED OUT\n");
        }
        printf("QUESTION %d: \n", totalq); 
        inp = -1;
        printf("%d + %d = \n", d1, d2);
        scanf("%d", &inp);
        time_out = 0;
        if (sum == inp)
        {
            printf("Correct\n");
            totalc++;
            time_out = 1;
            raise(SIGALRM);
        }
        else if(inp != -1){
            printf("Wrong! Answer is: %d\n", sum);
            time_out = 1;
            raise(SIGALRM);
        }
        
    }
    return 0;
}