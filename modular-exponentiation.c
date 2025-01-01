#include <stdio.h>

// Function to validate user input
long long validateInput(const char *prompt, long long minValue) {
    long long value;
    while (1) {
        printf("%s", prompt);
        scanf("%lld", &value);
        if (value >= minValue) {
            return value;
        } else {
            printf("Error: Value must be at least %lld. Please try again.\n", minValue);
        }
    }
}

// Function for modular exponentiation
long long modularExponentiation(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

int main() {
    long long base = validateInput("Enter the Base value: ", 1);
    long long exponent = validateInput("Enter the Exponent value: ", 0);
    long long modulus = validateInput("Enter the Modulus value: ", 2);

    // Calculate result
    long long result = modularExponentiation(base, exponent, modulus);

    printf("The result of (%lld^%lld) %% %lld is: %lld\n", base, exponent, modulus, result);

    return 0;
}
