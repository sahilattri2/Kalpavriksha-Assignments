#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Optimized function to check if two strings are anagrams
bool areAnagrams(const char *str1, const char *str2) {
   int count[26]={0};

    // If lengths are not the same, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    // Count character frequencies for str1 and str2
    for (int i = 0; str1[i]; i++) {
    count[str[i]-'a']++;
    count[str[i]-'a']--;
    }

for(int i=0;i<26;i++)
{
    if(count[i]!=0)
    {
return false;
    }
}

    return true;
}

int main() {
    char str1[100], str2[100];

    // Input strings
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Check if they are anagrams
    if (areAnagrams(str1, str2)) {
        printf("Output: true\n");
    } else {
        printf("Output: false\n");
    }

    return 0;
}
