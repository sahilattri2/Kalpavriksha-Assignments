#include <stdio.h>
#include <stdlib.h>

void calculateSpan(int* prices, int n, int* spans) {
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && prices[stack[top]] <= prices[i]) {
            top--;
        }
        if (top == -1) {
            spans[i] = i + 1;
        } else {
            spans[i] = i - stack[top];
        }
        stack[++top] = i;
    }
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);
    int* prices = (int*)malloc(n * sizeof(int));
    int* spans = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    calculateSpan(prices, n, spans);

    for (int i = 0; i < n; i++) {
        printf("%d ", spans[i]);
    }
    printf("\n");

    free(prices);
    free(spans);

    return 0;
}
