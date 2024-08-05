#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void extendedGcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return;
    }

    int x1, y1;
    extendedGcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
}

int main() {
    int a, b, x, y;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int resultGCD = gcd(a, b);
    printf("GCD of %d and %d is: %d\n", a, b, resultGCD);

    extendedGcd(a, b, &x, &y);
    printf("Extended Euclidean Algorithm:\n");
    printf("Coefficients x and y: %d, %d\n", x, y);
    printf("%d * %d + %d * %d = %d\n", a, x, b, y, resultGCD);

    return 0;
}

