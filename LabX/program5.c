#include <stdio.h>

void add(int a, int b, int c, int *result) {
    *result = a + b + c;
}

int main() {
    int a = 5, b = 10, c = 15;
    int sum;
    add(a, b, c, &sum);
    printf("Sum: %d\n", sum);
    return 0;
}
