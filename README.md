# DSA-ASSIGNMENT
This repo consists of my DSA assignments 
#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j, k, flag;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    k = 1; // position for next unique element
    for (i = 1; i < n; i++) {
        flag = 0; 
        for (j = 0; j < k; j++) { // check only unique part
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            arr[k] = arr[i]; // put unique element
            k++;
        }
    }

    printf("Array after removing duplicates:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
