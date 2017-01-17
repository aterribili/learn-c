#include <stdio.h>

void print_char(char string[]);

void print_char(char string[]) {
    printf("the size of %s is %ld\n", string, sizeof(string));
}

int main(int argc, char *argv[])
{
    int ages[] = {1,2,3,4,5};
    char *names[] = {"Abner", "Isabela", "Felipe", "Rodrigo", "Geraldo"};

    int count = sizeof(ages) / sizeof(int);

    for (int i = 0; i < count; i++) {
        printf("%s has %d years alive\n", names[i], ages[i]);
    }
    printf("---\n");

    int *cur_age = ages;
    char **cur_name = names;
    printf("%p test\n", cur_name+1);
    char *test = *(cur_name+1);
    printf("%c the value of whatever\n", *test);
    printf("%s test\n", test);
    printf("%s test\n", *(cur_name+1));
    printf("%p test\n", (void*)&names);

    char *pointer = "ola amigo!";
    printf("%p pointer xablau!\n", &pointer);
    printf("%s value xablau!\n", pointer);

    int *meu_pau = 10;

    printf("---\n");
    char *new_names[] = {};

    int testes[] = {10,20,30};
    int *testes_p = testes;
    char xablau[] = "uashduasdhuasdhuahdsuhasduhasudhasudhasudhuashduashduasdhuashduasduhasudhasudhasudhasudhuashduashduashduhshahahahahahahahahahahahhahhahahasudhausdhuasdhuashduashduhsd";
    char xablauzinho[] = "xablau";

    print_char(xablau);
    print_char(xablauzinho);
    char *oi = xablau;
    print_char(oi);
    printf("%ld size of char\n", sizeof(new_names));
    printf("%ld size of char\n", sizeof(names));
    printf("%ld, size of int\n", sizeof(int));
    printf("%ld size of char\n", sizeof(char));
    printf("---\n");

    for(int i=0; i < count; i++){
        printf("%s has %d years alive\n", *(cur_name + i), *(cur_age + i));
    }
    printf("---\n");

    for (int i = 0; i < count; i++) {
        printf("%s has %d years alive\n", cur_name[i], cur_age[i]);
    }
    printf("---\n");

    for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s has %d years alive\n", *cur_name, *cur_age);
    }

    return 0;
}
