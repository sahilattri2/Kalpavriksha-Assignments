#include <stdio.h>

#define MAX 100

int dfs(int x, int y, int rows, int cols, int matrix[MAX][MAX]) {
    if (x == rows - 1 && y == cols - 1) {
        return 1;
    }

    if (x < 0 || x >= rows || y < 0 || y >= cols || matrix[x][y] == 0) {
        return 0;
    }

    matrix[x][y] = 0;

    if (dfs(x + 1, y, rows, cols, matrix) || 
        dfs(x, y + 1, rows, cols, matrix) || 
        dfs(x - 1, y, rows, cols, matrix) || 
        dfs(x, y - 1, rows, cols, matrix)) {
        return 1;
    }

    return 0;
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the matrix (%d x %d) with 0s and 1s:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (matrix[0][0] == 1 && dfs(0, 0, rows, cols, matrix)) {
        printf("Path exists!\n");
    } else {
        printf("No path exists.\n");
    }

    return 0;
}
