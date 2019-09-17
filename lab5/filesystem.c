#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    __uint32_t valid;
    __uint32_t size;
    __uint32_t direct_ptr[5];
    __uint32_t singly_indirect;
} inode_t;

typedef struct 
{
    __uint32_t block_nums;

} indirect_block_t;
void write(){
    char location[50];
    printf("What file to write: ");
    scanf("%s", location);
    printf("%s", location);
}
int main(){
    char input;
    do{
        printf("Enter a command: ");
        scanf("%c", &input);
        switch (input)
        {
            case 'w':
                write();
                break;
            case 'r':
                printf("Write");
                break;
            case 'd':
                printf("Write");
                break;
            case 'b':
                printf("Write");
                break;
            case 'i':
                printf("Write");
                break;
            default:
                break;
        }
    }while(1);
}