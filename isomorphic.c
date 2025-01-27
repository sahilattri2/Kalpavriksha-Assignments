#include <stdio.h>

#define MAX_CHAR 256

int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int isIsomorphic(char *s, char *t) {
    if (stringLength(s) != stringLength(t)) {
        return 0;
    }

    int seenS[MAX_CHAR] = {0};
    int seenT[MAX_CHAR] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        char s_char = s[i];
        char t_char = t[i];

        if (seenS[s_char] != seenT[t_char]) {
            return 0;
        }

        seenS[s_char] = i + 1;
        seenT[t_char] = i + 1;
    }

    return 1;
}

int main() {
    char s[100], t[100];

    printf("Enter the first string: ");
    scanf("%s", s);

    printf("Enter the second string: ");
    scanf("%s", t);

    if (isIsomorphic(s, t) == 1) {
        printf("The strings \"%s\" and \"%s\" are isomorphic.\n", s, t);
    } else {
        printf("The strings \"%s\" and \"%s\" are not isomorphic.\n", s, t);
    }

    return 0;
}
