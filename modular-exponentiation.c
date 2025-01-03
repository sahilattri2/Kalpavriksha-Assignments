#include <stdio.h>
// Reads and validates user input based on a minimum value
long long readAndValidateInput(const char *prompt, long long minValue)
 {
    long long value;
    int isValid;
    int isInputValid = 0;// Control variable

    while (!isInputValid) 
    {
        printf("%s", prompt);
        isValid = scanf("%lld", &value);

        if (isValid == 1 && value >= minValue)
         {
            isInputValid = 1;
        } else
         {
            printf("Error: Value must be at least %lld. try again.\n", minValue);
        }
    }
    return value;
}

// calculates (base^exponent) % modulus
long long modularExponentiation(long long base, long long exponent, long long modulus)
 {
    if (modulus == 1) 
    return 0;
    long long result = 1;
    base = base % modulus;

    while (exponent > 0) 
    {
        if (exponent % 2 == 1) 
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

int main() 
{
    long long base = readAndValidateInput("Enter the Base value: ", 1);
    long long exponent = readAndValidateInput("Enter the Exponent value: ", 0);
    long long modulus = readAndValidateInput("Enter the Modulus value: ", 2);

    long long result = modularExponentiation(base, exponent, modulus);
    printf("The result of (%lld^%lld) %% %lld is: %lld\n", base, exponent, modulus, result);

    return 0;
}
