#include<stdio.h>
#include<ctype.h>
#include<string.h>

// forward declarations
int can_print_it(char ch);
void print_letters(int lenght, char arg[]);

void print_arguments(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++) {
        char *ch = argv[i];
        print_letters(strlen(ch), ch);
    }
}

void print_letters(int lenght, char arg[])
{
    for(int i = 0; i < lenght; i++) {
        char ch = arg[i];

        if (can_print_it(ch)) {
            printf("'%c' == '%d'", ch, ch);
        } else {
            printf("chose poorly %c", ch);
        }
    }

    printf("\n");
}

int can_print_it(char ch)
{
    int new = (int)ch;
    return isupper(new) || islower(new) || isblank(new);
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}

