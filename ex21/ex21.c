#include <stdio.h>
#include "../dbg.h"
#include <string.h>
#include <stdlib.h>

typedef void (*thing)(const char term[]);

void print_xablau(const char term[]){
    debug("this is the %s", term);
}

int sum(int x, int y, thing th)
{
    th("doing the sum");
    return x + y;
}

struct Dog {
    char *name;
    int age;
    double weight;
};

struct Dog *Dog_create(char *name, int age, double weight)
{
    struct Dog *dog = malloc(sizeof(struct Dog));
    check_mem(dog);
    dog->name = name;
    dog->age = age;
    dog->weight = weight;

    return dog;

error:
    free(dog->name);
    free(dog);
    return NULL;
}

struct Dog Dog_new(char *name, int age, double weight)
{
    struct Dog dog;
    dog.name = name;
    dog.age = age;
    dog.weight = weight;

    return dog;
}

void print_test(char *printable, int command) {
    if (command == 1) {
        goto one;
    }

    if (command == 2) {
        goto two;
    }

one:
    debug("the one and %s", printable);
    return;

two:
    debug("the two and %s", printable);
    return;
}

int main(int argc, char *argv[])
{
    void (*my_thing)(const char *term);
    my_thing = &print_xablau;
    debug("address of thing %p", my_thing);
    debug("address of print_xablau %p", print_xablau);
    print_xablau("amor");
    (*my_thing)("amor");
    int x = sum(10, 20, &print_xablau);
    debug("The value of sum is %d", x);
    long my_num = 10;
    const unsigned long num = my_num;
    my_num = 20;
    debug("The unsigned value of num is %lu.", num);

    const char *name = "abner";
    debug("the name address is %p", &name);
    debug("the name value is %s", name);
    debug("the name address is %c", (*name)+1);

    const char *full_name = name;

    debug("the full_name address is %p", &full_name);
    debug("the full_name value is %s", full_name);
    debug("the full_name address is %c", (*full_name)+1);

    char *dg_name = "pingo";
    struct Dog *dog = Dog_create(dg_name, 15, 2.6);
    debug("heap dog");
    debug("the dog's name is %s", dog->name);
    debug("the dog's age is %d", dog->age);
    debug("the dog's weight is %f", dog->weight);
    debug("the dog's adress is %p", &dog);

    debug("\n");

    struct Dog new_dog = Dog_new(dg_name, 15, 2.6);
    debug("stack dog");
    debug("the dog's name is %s", new_dog.name);
    debug("the dog's age is %d", new_dog.age);
    debug("the dog's weight is %f", new_dog.weight);
    debug("the dog's adress is %p", &new_dog);

    dg_name = "new xablau";
    debug("the dog's name is %s", new_dog.name);
    debug("the dog's name is %s", dog->name);
    debug("the dog's pointer name address is %p", &(new_dog.name));
    debug("the dog's pointer name address is %p", &(dog->name));

    debug("\n");

    print_test("xablau!", 1);
    print_test("xablau!", 2);
    return 0;
}

