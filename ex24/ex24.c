#include <stdio.h>
#include <stdlib.h>
#include "../dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES,
    BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char *argv[])
{
    Person you = {.age = 0};
    int i = 0;
    char *in = NULL;

    printf("what's your fist name?");
    in = fgets(you.first_name, MAX_DATA -1, stdin);
    check(in != NULL, "failed to read first name.");

    printf("whats your last name?");
    in = fgets(you.last_name, MAX_DATA - 1, stdin);
    check(in != NULL, "failed to read last name.");

    char age[256];
    printf("how old are you?");
    in = fgets(age, 256, stdin);
    printf("current age %s\n", age);
    check(in != NULL, "failed to read age.");
    int new_age = atoi(age);
    check(new_age > 0, "you have to enter a number");
    you.age = new_age;

    printf("what color are you eyes?");
    for (i = 0; i <= OTHER_EYES;i++) {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    int rc = 0;
    rc = fscanf(stdin, "%d", &eyes);
    check(rc > 0, "you have to enter a number");

    you.eyes = eyes - 1;
    check(you.eyes <= OTHER_EYES && you.eyes >= 0, "do it right, that's not an option.");

    printf("how much do you make an hour?");
    rc = fscanf(stdin, "%f", &you.income);
    check(rc > 0, "enter a floating point number.");

    printf("------RESULTS-----\n");

    printf("first name %s\n", you.first_name);
    printf("last name %s\n", you.first_name);
    printf("age %d\n", you.age);
    printf("eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("income: %f\n", you.income);

    return 0;

error:
    return -1;
}









