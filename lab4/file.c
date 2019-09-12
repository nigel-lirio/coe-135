#include <stdlib.h>
#include <stdio.h>
int main(){
    char name[] = "Nigel";
    char test[10];
    FILE *pt;
    pt = fopen("fv.txt", "w");
    fwrite(name, sizeof(name),1,pt);
    fclose(pt);
    pt = fopen("fv.txt", "r");
    fread(test, 1, sizeof(name), pt);
    printf("%s\n", test);
    fclose(pt);
}