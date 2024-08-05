#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; 
}

void solveLinearCongruence(int a, int b, int m) {
    int g = gcd(a, m);
    
   
    if (b % g != 0) {
        printf("No solution exists.\n");
        return;
    }

 
    a /= g;
    b /= g;
    m /= g;

    int a_inv = modInverse(a, m);
    
    if (a_inv == -1) {
        printf("No modular inverse exists.\n");
        return;
    }


    int x = (a_inv * b) % m;

    
    printf("Solutions to the linear congruence:\n");
    for (int i = 0; i < g; i++) {
        printf("x = %d + %d * %d\n", x + i * m, i, m);
    }
}

int main() {
    int a, b, m;

    printf("Enter coefficients a, b, and modulus m (a * x = b (mod m)):\n");
    scanf("%d %d %d", &a, &b, &m);

    solveLinearCongruence(a, b, m);

    return 0;
}

