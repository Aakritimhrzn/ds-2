#include <stdio.h>

void findPrimeFactors(int n) {

    while (n % 2 == 0) {
        printf("%d ", 2);
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }

    if (n > 2) {
        printf("%d ", n);
    }
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Prime factors of %d are: ", number);
    findPrimeFactors(number);
    printf("\n");

    return 0;
}

