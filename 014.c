#include <stdio.h>

int main() {
    int n;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int isIdentity = 1;

    for (int i = 0; i < n && isIdentity; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && a[i][j] != 1) {
                isIdentity = 0;
                break;
            }
            if (i != j && a[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
    }

    if (isIdentity)
        printf("Matrix is an Identity Matrix\n");
    else
        printf("Matrix is NOT an Identity Matrix\n");

    return 0;
}
