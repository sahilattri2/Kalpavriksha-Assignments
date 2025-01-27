#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isRotation(const char *str1, const char *str2) {
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    char temp[2 * strlen(str1) + 1];
    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2) != NULL) {
        return true;
    }

    return false;
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    if (isRotation(str1, str2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}
-------------------------------------------->
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isRotation(const char *str1, const char *str2) {
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    int len = strlen(str1);

    for (int i = 0; i < len; i++) {
        bool match = true;

        for (int j = 0; j < len; j++) {
            if (str1[(i + j) % len] != str2[j]) {
                match = false;
                break;
            }
        }

        if (match) {
            return true;
        }
    }

    return false;
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (isRotation(str1, str2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
------------------------------------------------->
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void concatenateStrings(char *result, const char *str1) {
    int len1 = strlen(str1);
    for (int i = 0; i < len1; i++) {
        result[i] = str1[i];
    }
    for (int i = 0; i < len1; i++) {
        result[len1 + i] = str1[i];
    }
    result[2 * len1] = '\0'; // Null-terminate the concatenated string
}

bool isSubstring(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2) {
        return false; // If str1 is shorter than str2, str2 can't be a substring
    }

    for (int i = 0; i <= len1 - len2; i++) {
        int j = 0;
        while (j < len2 && str1[i + j] == str2[j]) {
            j++;
        }
        if (j == len2) {
            return true;
        }
    }
    return false;
}

bool isRotation(const char *str1, const char *str2) {
    if (strlen(str1) != strlen(str2)) {
        return false; // Strings must be of the same length
    }

    char concatenated[2 * strlen(str1) + 1];
    concatenateStrings(concatenated, str1);

    return isSubstring(concatenated, str2);
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    if (isRotation(str1, str2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}
