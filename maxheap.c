#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10
int number = 0;



void maxHeapSort(int *arr, int n){
    int temp = n;
    while (temp>1){
        if (arr[temp/2]<arr[temp]){
            int t = arr[temp/2];
            arr[temp/2] = arr[temp];
            arr[temp] = t;            
        }
        temp--;
    }
}




int main(){
    int arr[] = {0,5, 2, 9, 1, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxHeapSort(arr, n-1);

    printf("after sort：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    //popMax(arr,n-1);
    arr[1] =  arr[n-1];
    maxHeapSort(arr, n-2);
    printf("after sort2：");
    for (int i = 0; i < n-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}