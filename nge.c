#include <stdio.h>
#include <stdlib.h>

void nge(int N, int A[]) {
    int *stack = (int *)malloc(N * sizeof(int));  // Allocate memory for stack
    int *result = (int *)malloc(N * sizeof(int)); // Allocate memory for result
    int top = -1;
    
    for (int i = N - 1; i >= 0; i--) {
        while (top >= 0 && A[stack[top]] <= A[i]) {
            top--;
        }
        
        if (top == -1) {
            result[i] = -1;
        } else {
            result[i] = A[stack[top]];
        }
        
        stack[++top] = i;
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);  // Print with space between each number
    }
    
    free(stack);  // Free memory for stack
    free(result); // Free memory for result
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    nge(N, A);
    
    return 0;
}
