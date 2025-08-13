#include <stdio.h>
int main(){
int arr[100];
int n, i, j, k,flag;

printf("Enter size of array: ");
scanf("%d", &n);
printf("Enter elements:\n");
for (i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

i=arr[1];
j=arr[1];
while(i<n-1){
    for(j=0;j<=i-1;j++){
        flag==0;
        if(arr[j]==arr[i]){
        i++;
        flag==1;
        }break;
        if (flag==1) {
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
}
