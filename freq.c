#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int key, value;
} HashMap;
 
void countFrequency(int arr[], int n, int result[]) {
    HashMap* map = (HashMap*)calloc(n, sizeof(HashMap));
    for (int i = 0; i < n; i++) {
        map[arr[i] - 1].key = arr[i];
        map[arr[i] - 1].value++;
    }
    for (int i = 0; i < n; i++) 
    result[i] = map[i].value;
    free(map);
}
 
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    printf("\n");
}
 
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
 
    int arr[n], result[n];
 
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
 
    countFrequency(arr, n, result);
    printArray(result, n);
 
    return 0;
}