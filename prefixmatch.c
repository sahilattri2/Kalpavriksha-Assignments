#include <stdio.h>

int startsWith(char *word, char *prefix) {
    int i = 0;
    while (prefix[i] != '\0') {
        if (word[i] != prefix[i]) {
            return 0; 
        }
        i++;
    }
    return 1;
}

int main() {
    int wordCount;
    printf("Enter the number of words: ");
    scanf("%d", &wordCount);

    char words[wordCount][50];
    printf("Enter the words:\n");
    for (int i = 0; i < wordCount; i++) {
        scanf("%s", words[i]);
    }

    char prefix[50];
    printf("Enter prefix: ");
    scanf("%s", prefix);

    printf("Words with prefix '%s':\n", prefix);
    int found = 0;
    for (int i = 0; i < wordCount; i++) {
        if (startsWith(words[i], prefix)) {
            printf("%s\n", words[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No words found with prefix '%s'.\n", prefix);
    }

    return 0;
}
