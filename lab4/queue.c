#include <stdlib.h>
#include <stdio.h>

struct item {
    int x;
    struct item *next;
};

int main(){
    struct item *coolqueue = NULL, *hold, *inpq, *nlast;
    int stop = 0, elements = 0, inp;
    do{
        printf("Enter int element to insert (0 to exit): ");
        scanf("%d", &inp);
        if(inp != 0){
            elements++;
            inpq = (struct item*)malloc(sizeof(struct item));
            inpq->x = inp;
            inpq->next = NULL;
            if(coolqueue == NULL){
                coolqueue = inpq;
            }
            else{
                hold = coolqueue;
                while(hold->next != NULL){
                    hold = hold->next;
                }
                hold->next = inpq;
            }
        }
        else{
            stop = 1;
        }
    }while(stop == 0);
    while(elements > 0 && coolqueue != NULL){
        elements--;
        if(coolqueue->next == NULL){
            inp = coolqueue->x;
            printf("POPPING: %d\n", inp);
            free(coolqueue);
            coolqueue = NULL;
            printf("QUEUE EMPTY!\n");
        }
        else{
            hold = coolqueue;
            inp = coolqueue->x;
            coolqueue = coolqueue->next;
            printf("POPPING: %d\n", inp);
            free(hold);
        }
    }
}