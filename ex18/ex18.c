#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR %s\n", message);
    }

    exit(1);
}

typedef int (*compare_cb) (int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cmb) {
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count *sizeof(int));

    if (!target)
        die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for (i = 0; i < count; i++){
        for(j = 0; j < count - 1; j++) {
            if (cmb(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b) {
    return (a>b) - (a<b);
}

int reverse_order(int a, int b) {
    return (a<b) - (a>b);
}

int strange_order(int a, int b) {
    if (a==0 || a == 0) {
        return 0;
    } else {
        return a % b;
    }
}

int xablau(int a, int b) {
    return a + b;
}

void test_sorting(int *numbers, int count, compare_cb cmp, const char functionName[])
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);

    if (!sorted) {
        die("Failed to sort as requested");
    }

    printf("Function %s:", functionName);

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }

    printf("\n");

    free(sorted);

    //unsigned char *data = (unsigned char *)cmp;
//    for (i = 0; i < 25; i++) {
 //       printf("%02x:", data[i]);
  //  }
   // printf("\n");
}

void crazy_sorting(int *numbers, int count, compare_cb cmp1, compare_cb cmp2) {
    test_sorting(numbers, count, cmp1, __func__);
    test_sorting(numbers, count, cmp2, __func__);
}


int main(int argc, char *argv[]) {
    if (argc < 2) die("USAGE ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error.");

    for (i = 0; i < count; i ++) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order, "sorted_order");
    test_sorting(numbers, count, reverse_order, "reverse_order");
    test_sorting(numbers, count, strange_order, "strange_order");
    test_sorting(numbers, count, xablau, "xablau");
    crazy_sorting(numbers, count, sorted_order, xablau);

    free(numbers);

    return 0;
}
