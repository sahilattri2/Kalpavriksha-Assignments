#include <stdio.h>
#include <string.h>

void frequencySort(char str[]) {
    int count[256] = {0};
    for (int i = 0; str[i] != '\0'; i++)
        count[(unsigned char)str[i]]++;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i + 1; str[j] != '\0'; j++) {
            if (count[str[j]] > count[str[i]] || (count[str[j]] == count[str[i]] && str[j] < str[i])) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[] = "banana";
    frequencySort(str);
    printf("Sorted by frequency: %s\n", str);
    return 0;
}
