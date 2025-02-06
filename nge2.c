#include <stdio.h>
#include <stdlib.h>

void nextGreaterElements(int* nums, int numsSize, int* result) {
    int *stack = (int *)malloc(numsSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < 2 * numsSize; i++) {
        while (top >= 0 && nums[stack[top]] < nums[i % numsSize]) {
            result[stack[top]] = nums[i % numsSize];
            top--;
        }

        if (i < numsSize) {
            stack[++top] = i;
        }
    }

    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);
    int *nums = (int *)malloc(n * sizeof(int));
    int *result = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    nextGreaterElements(nums, n, result);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(nums);
    free(result);

    return 0;
}
