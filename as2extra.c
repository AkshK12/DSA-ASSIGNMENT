//additional ques of assignment 2 aksh kaushik 1024030660 in c programming
#include <stdio.h>
#include <stdlib.h>

int countpair(int arr[], int k, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == k)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int arr[] = {1, 4, 1, 4, 5};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", countpair(arr, k, n));
    return 0;
}
// ques3.c
#include <stdio.h>
#include <string.h>

// Bubble sort function for character arrays
void sortstr(char str[]) {
    int l = strlen(str);
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < l - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}


//QUES 3
int main() {
    char str1[100], str2[100];

    printf("Enter string 1:\n");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // remove trailing newline

    printf("Enter string 2:\n");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    sortstr(str1);
    sortstr(str2);

    if (strcmp(str1, str2) == 0) {
        printf("Both strings are anagrams\n");
    } else {
        printf("Strings are not anagrams\n");
    }

    return 0;
}

//QUES 4
#include <stdio.h>

int main() {
    int a[] = {0, 2, 1, 0, 1, 2, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            int temp = a[mid];
            a[mid] = a[low];
            a[low] = temp;
            mid++;
            low++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            int temp = a[mid];
            a[mid] = a[high];
            a[high] = temp;
            high--;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

//QUES 5

#include <stdio.h>

int main() {
    int a[100] = {0, 1, 2, 4, 5, 2, 6, 7};
    int size = 8;
    
    for (int i = 0; i < size; i++) {
        if (a[i] == 2) {
            // Shift elements to the right
            for (int j = size; j > i + 1; j--) {
                a[j] = a[j - 1];
            }
            a[i + 1] = 2;  // Insert duplicate 2 one place ahead
            size++;        // Increase array size
            i++;           // Skip the newly inserted 2
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
