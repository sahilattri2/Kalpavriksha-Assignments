#include <stdio.h>
#include <stdlib.h>

void findNearestSmallerElement(int arr[], int n) 
{
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    int result[n];

    for (int i = 0; i < n; i++) {
        while (top != -1 && stack[top] >= arr[i]) {
            top--;
        }

        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = stack[top];
        }

        stack[++top] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    free(stack);
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    findNearestSmallerElement(arr, n);

    return 0;
}
// #include <stdio.h>

// void findNearestSmallerElement(int arr[], int n) {
//     int result[n];

//     for (int i = 0; i < n; i++) {
//         result[i] = -1;
//         for (int j = i - 1; j >= 0; j--) {
//             if (arr[j] < arr[i]) {
//                 result[i] = arr[j];
//                 break;
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         printf("%d ", result[i]);
//     }
// }

// int main() {
//     int arr[] = {4, 5, 2, 10, 8};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     findNearestSmallerElement(arr, n);

//     return 0;
// }
