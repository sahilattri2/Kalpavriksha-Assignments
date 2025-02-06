#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int key, value;
} HashMap;
 
void countFrequency(int arr[], int n, int result[], int *maxFreq, int *minFreq, int *maxElem, int *minElem)
 {
    HashMap* map = (HashMap*)calloc(n, sizeof(HashMap));
 
    for (int i = 0; i < n; i++) {
        map[arr[i] - 1].key = arr[i];
        map[arr[i] - 1].value++;
    }
 
    *maxFreq = 0, *minFreq = n + 1, *maxElem = -1, *minElem = -1;
 
    for (int i = 0; i < n; i++) {
        result[i] = map[i].value;
        if (map[i].value > 0) {
            if (map[i].value > *maxFreq) {
                *maxFreq = map[i].value;
                *maxElem = map[i].key;
            }
            if (map[i].value < *minFreq) {
                *minFreq = map[i].value;
                *minElem = map[i].key;
            }
        }
    }
 
    free(map);
}
 
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
 
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
 
    int arr[n], result[n], maxFreq, minFreq, maxElem, minElem;
 
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
 
    countFrequency(arr, n, result, &maxFreq, &minFreq, &maxElem, &minElem);
 
    printf("Frequency Array: ");
    printArray(result, n);
 
    printf("Highest Frequency Element: %d (Frequency: %d)\n", maxElem, maxFreq);
    printf("Lowest Frequency Element: %d (Frequency: %d)\n", minElem, minFreq);
 
    return 0;
}
 