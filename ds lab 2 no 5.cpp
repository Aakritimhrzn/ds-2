#include <stdio.h>


int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; 
}

// Function to implement the Chinese Remainder Theorem
int chineseRemainder(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++) {
        prod *= num[i];
    }

    int result = 0;

    for (int i = 0; i < k; i++) {
        int p = prod / num[i];
        int inv = modInverse(p, num[i]);
        result += rem[i] * inv * p;
    }

    return result % prod;
}

int main() {
    int k;
    printf("Enter the number of equations (congruences): ");
    scanf("%d", &k);
    
    int num[k], rem[k];

    printf("Enter the moduli:\n");
    for (int i = 0; i < k; i++) {
        printf("num[%d]: ", i);
        scanf("%d", &num[i]);
    }

    printf("Enter the remainders:\n");
    for (int i = 0; i < k; i++) {
        printf("rem[%d]: ", i);
        scanf("%d", &rem[i]);
    }

    int result = chineseRemainder(num, rem, k);
    
    printf("The solution is x = %d (mod %d)\n", result, num[0] * num[1] * num[2]); // Adjust for multiple moduli

    return 0;
}

