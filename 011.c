#include <stdio.h>

int main() {
    int r, c;
    int A[10][10], B[10][10], Sum[10][10];
    int i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    if(r > 10 || c > 10) {
        printf("Size should be <= 10\n");
        return 0;
    }

    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Sum of matrices:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", Sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
