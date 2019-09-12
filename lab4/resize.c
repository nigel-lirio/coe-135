#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr;
    int n = 2;
    arr = (int*)calloc(n, sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    printf("%d , %d", arr[0], arr[1]);
}