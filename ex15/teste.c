#include<stdio.h>

int main(int argc, char *argv[])
{
    char ch = 'a';
    printf("%p the adress of char.\n", &ch);
    printf("%c char value.\n", ch);

    printf("-----\n");

    char *array[] = {"abner", "bela", "renata", "rita"};
    printf("%s first string on array value.\n", *(array));
    printf("%p poninter :)\n", array);
    printf("size of char %lu\n", sizeof(char));
    for(int i = 0; i < 4; i++){
        printf("%p the adress of %s elem.\n", &*(array+i), array[i]);
    }

    printf("-----\n");

    char string[] = "";
    printf("%s string value.\n", string);

    return 0;
}
