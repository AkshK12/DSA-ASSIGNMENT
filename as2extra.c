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
