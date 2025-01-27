#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge(arr, left, mid);
        merge(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1], rightArr[n2];
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }

        while (i < n1) {
            arr[k++] = leftArr[i++];
        }
        while (j < n2) {
            arr[k++] = rightArr[j++];
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int twoPointerSearch(int arr[], int n, int sum) {
    int left = 0, right = n - 1;
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == sum) {
            return 1;
        } else if (currentSum < sum) {
            left++;
        } else {
            right--;
        }
    }
    return 0;
}

int main() {
    int n, choice, x, sum;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Linear Search\n");
        printf("7. Binary Search\n");
        printf("8. Two Pointer Technique\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("Array after Bubble Sort: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                selectionSort(arr, n);
                printf("Array after Selection Sort: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                insertionSort(arr, n);
                printf("Array after Insertion Sort: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                merge(arr, 0, n - 1);
                printf("Array after Merge Sort: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 5:
                quickSort(arr, 0, n - 1);
                printf("Array after Quick Sort: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Enter the element to search for: ");
                scanf("%d", &x);
                int linearResult = linearSearch(arr, n, x);
                if (linearResult != -1) {
                    printf("Element found at index %d\n", linearResult);
                } else {
                    printf("Element not found\n");
                }
                break;

            case 7:
                printf("Enter the element to search for: ");
                scanf("%d", &x);
                int binaryResult = binarySearch(arr, n, x);
                if (binaryResult != -1) {
                    printf("Element found at index %d\n", binaryResult);
                } else {
                    printf("Element not found\n");
                }
                break;

            case 8:
                printf("Enter the sum to search for: ");
                scanf("%d", &sum);
                int twoPointerResult = twoPointerSearch(arr, n, sum);
                if (twoPointerResult) {
                    printf("Pair with the sum found\n");
                } else {
                    printf("No pair found with the sum\n");
                }
                break;

            case 9:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
