#include <stdio.h>

int main() {
    int m1, n1, m2, n2, choice;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &m1, &n1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &m2, &n2);

    int A[m1][n1];
    int B[m2][n2];
    int R[m1 > m2 ? m1 : m2][n1 > n2 ? n1 : n2];

    int i, j, k;

    printf("\nEnter values for first matrix:\n");
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            scanf("%d", &A[i][j]);


    printf("Matrix A is:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter values for second matrix:\n");
    for (i = 0; i < m2; i++)
        for (j = 0; j < n2; j++)
            scanf("%d", &B[i][j]);
    
    printf("Matrix B is:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    do {
        printf("\nChoose operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (m1 != m2 || n1 != n2) {
                    printf("Addition not possible.\n");
                    break;
                }
                printf("\nResult (A + B):\n");
                for (i = 0; i < m1; i++) {
                    for (j = 0; j < n1; j++) {
                        R[i][j] = A[i][j] + B[i][j];
                        printf("%d\t", R[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                if (m1 != m2 || n1 != n2) {
                    printf("Subtraction not possible.\n");
                    break;
                }
                printf("\nResult (A - B):\n");
                for (i = 0; i < m1; i++) {
                    for (j = 0; j < n1; j++) {
                        R[i][j] = A[i][j] - B[i][j];
                        printf("%d\t", R[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                if (n1 != m2) {
                    printf("Multiplication not possible.\n");
                    break;
                }
                printf("\nResult (A x B):\n");
                for (i = 0; i < m1; i++) {
                    for (j = 0; j < n2; j++) {
                        R[i][j] = 0;
                        for (k = 0; k < n1; k++)
                            R[i][j] += A[i][k] * B[k][j];
                        printf("%d\t", R[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
