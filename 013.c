#include <stdio.h>

void spiralPrint(int rows, int cols, int matrix[rows][cols]) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {

       
        for (int j = left; j <= right; j++)
            printf("%d ", matrix[top][j]);
        top++;

        
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

       
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", matrix[bottom][j]);
            bottom--;
        }

      
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

int main() {
    int mat[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    spiralPrint(3, 4, mat);
    return 0;
}
