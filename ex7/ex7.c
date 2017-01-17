#include<stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = {10,20,30,40,50};
    areas[0] = 90;
    areas[100] = 100;
    char name[] = "Zed";
    char full_name[] = {'A', 'b', 'n', 'e', 'r', '\0'};

    printf("position five: %d\n", areas[100]);
    printf("The size of an int %ld\n", sizeof(int));
    printf("The size of areas (int[]) %ld\n", sizeof(areas));
    printf("The size of ints in areas %ld\n", (sizeof(areas) / sizeof(int)));
    printf("The first elem of areas is %d and 2nd %d\n", areas[0], areas[1]);
    printf("The size of a char: %ld\n", sizeof(char));
    printf("the size of the name: %ld\n", sizeof(name));
    printf("the number os chars in name: %ld\n", (sizeof(name) / sizeof(char)));
    printf("the size of full name %ld\n", sizeof(full_name));
    printf("the number of chars in full name: %ld\n", (sizeof(full_name) / sizeof(char)));
    printf("name=\"%s\" and full name=\"%s\"\n", name, full_name);
}
