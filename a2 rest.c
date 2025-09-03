//5th and 6th ques
#include <stdio.h>
#include <stdlib.h>

void diagonalMatrix() {
    int size;
    printf("Enter the size for Diagonal Matrix: ");
    scanf("%d", &size);

    int* diagonal = malloc(size * sizeof(int));
    printf("Enter the diagonal elements:\n");

    for (int i = 0; i < size; ++i) {
        printf("Matrix [%d][%d]: ", i + 1, i + 1);
        scanf("%d", &diagonal[i]);
    }

    printf("Diagonal Matrix:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                printf("%d ", diagonal[i]);
            } else {
                printf("0 ");
            }
        }
        puts("");
    }
    puts("");

    free(diagonal);
}

void triDiagonalMatrix() {
    int size;
    printf("Enter the size for Tri-Diagonal Matrix: ");
    scanf("%d", &size);

    int* triDiagonal = malloc((3 * size - 2) * sizeof(int));
    int* ptr         = triDiagonal;

    printf("Enter the diagonal elements:\n");
    for (int i = 0; i < size; ++i) {
        printf("Matrix [%d][%d]: ", i + 1, i + 1);
        scanf("%d", ptr);
        ++ptr;
    }

    printf("Enter the first upper diagonal elements:\n");
    for (int i = 0; i < size - 1; ++i) {
        printf("Matrix [%d][%d]: ", i + 1, i + 2);
        scanf("%d", ptr);
        ++ptr;
    }

    printf("Enter the first lower diagonal elements:\n");
    for (int i = 0; i < size - 1; ++i) {
        printf("Matrix [%d][%d]: ", i + 2, i + 1);
        scanf("%d", ptr);
        ++ptr;
    }

    printf("Tri-Diagonal Matrix:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                printf("%d ", triDiagonal[i]);
            } else if (i == j - 1) {
                printf("%d ", triDiagonal[size + i]);
            } else if (i - 1 == j) {
                printf("%d ", triDiagonal[size + size - 1 + j]);
            } else {
                printf("0 ");
            }
        }
        puts("");
    }
  // Store Lower Triangular Matrix
void storeLowerTriangular(int arr[], int n) {
    int i, j, index;
    printf("\nEnter elements of Lower Triangular Matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            index = (i * (i + 1)) / 2 + j;
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[index]);
        }
    }
}

// Display Lower Triangular Matrix
void displayLowerTriangular(int arr[], int n) {
    int i, j, index;
    printf("\nLower Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i >= j) {
                index = (i * (i + 1)) / 2 + j;
                printf("%d ", arr[index]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// ---------------- UPPER TRIANGULAR ----------------
// Store Upper Triangular Matrix
void storeUpperTriangular(int arr[], int n) {
    int i, j, index;
    printf("\nEnter elements of Upper Triangular Matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            index = (j * (j + 1)) / 2 + i;
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[index]);
        }
    }
}

// Display Upper Triangular Matrix
void displayUpperTriangular(int arr[], int n) {
    int i, j, index;
    printf("\nUpper Triangular Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i <= j) {
                index = (j * (j + 1)) / 2 + i;
                printf("%d ", arr[index]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
    puts("");

    free(triDiagonal);
}






//6 th ques
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Structure for triplet representation
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to read a sparse matrix
void readSparse(struct SparseMatrix a[], int *total) {
    int rows, cols, i, j, val;
    int count = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &val);
            if (val != 0) {
                a[count].row = i;
                a[count].col = j;
                a[count].value = val;
                count++;
            }
        }
    }

    // First element stores rows, columns, and total non-zero count
    a[count].row = rows;
    a[count].col = cols;
    a[count].value = count;

    *total = count;
}

// Display sparse matrix
void displaySparse(struct SparseMatrix a[], int total) {
    int i;
    printf("\nRow\tCol\tValue\n");
    printf("---------------------\n");
    for (i = 0; i < total; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

// (a) Transpose of a sparse matrix
void transpose(struct SparseMatrix a[], struct SparseMatrix t[], int total) {
    int i, j, k = 0;

    int rows = a[total].row;
    int cols = a[total].col;

    // Swap rows and columns
    for (i = 0; i < cols; i++) {
        for (j = 0; j < total; j++) {
            if (a[j].col == i) {
                t[k].row = a[j].col;
                t[k].col = a[j].row;
                t[k].value = a[j].value;
                k++;
            }
        }
    }

    t[k].row = cols;
    t[k].col = rows;
    t[k].value = k;
}

// (b) Addition of two sparse matrices
void addSparse(struct SparseMatrix a[], struct SparseMatrix b[], struct SparseMatrix sum[], int totalA, int totalB) {
    int i = 0, j = 0, k = 0;

    if (a[totalA].row != b[totalB].row || a[totalA].col != b[totalB].col) {
        printf("Addition not possible: Matrix dimensions don't match.\n");
        return;
    }

    while (i < totalA && j < totalB) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            sum[k++] = a[i++];
        } else if (b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col)) {
            sum[k++] = b[j++];
        } else {
            sum[k] = a[i];
            sum[k].value = a[i].value + b[j].value;
            i++;
            j++;
            if (sum[k].value != 0)
                k++;
        }
    }

    // Remaining elements
    while (i < totalA) sum[k++] = a[i++];
    while (j < totalB) sum[k++] = b[j++];

    sum[k].row = a[totalA].row;
    sum[k].col = a[totalA].col;
    sum[k].value = k;
}
