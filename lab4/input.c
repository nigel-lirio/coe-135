#include <stdio.h>

int main(){
    char x[162];
    fgets(x, 162, stdin);
    printf("PRINT: %s", x);
}