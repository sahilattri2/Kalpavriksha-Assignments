#include <stdio.h>

int stringLength(const char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void reverseString(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void rotateWord(char *word, int len, int rotations, int direction) {
    if (len <= 1) return;
    
    rotations = rotations % len;
    if (rotations < 0) rotations += len;
    if (rotations == 0) return;

    if (direction == 2) {
        reverseString(word, 0, len - 1);
        reverseString(word, 0, rotations - 1);
        reverseString(word, rotations, len - 1);
    } else if (direction == 1) {
        reverseString(word, 0, rotations - 1);
        reverseString(word, rotations, len - 1);
        reverseString(word, 0, len - 1);
    }
}

void rotateSentence(char *sentence, int rotations, int direction) {
    char *word = sentence;
    int wordLen = 0;
    
    for (int i = 0; ; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            rotateWord(word, wordLen, rotations, direction);
            if (sentence[i] == '\0') break;
            word = &sentence[i + 1];
            wordLen = 0;
        } else {
            wordLen++;
        }
    }
}

int main() {
    char sentence[100];
    int rotations, direction;

    printf("Enter a sentence: ");
    scanf(" %[^\n]", sentence);

    printf("Enter the number of rotations: ");
    scanf("%d", &rotations);

    do {
        printf("Choose rotation direction (1 for Left or  2 for Right): ");
        scanf("%d", &direction);
        if (direction != 1 && direction != 2) {
            printf("Invalid choice! Please enter 1 or 2.\n");
        }
    } while (direction != 1 && direction != 2);

    printf("Original sentence: %s\n", sentence);
    rotateSentence(sentence, rotations, direction);
    printf("Rotated sentence: %s\n", sentence);

    return 0;
}
