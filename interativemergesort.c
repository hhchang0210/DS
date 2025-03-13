#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>


void merge(int *arr, int position, int mid, int right){
    int n1 = mid - position + 1;
    int n2 = right - mid;
    int *p1 = malloc(n1 * sizeof(int));
    int *p2 = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        p1[i] = arr[position + i];
    for (int j = 0; j < n2; j++)
        p2[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = position;
        while (i < n1 && j < n2) {
            if (p1[i] <= p2[j]) {
                arr[k] = p1[i];
                i++;
            } else {
                arr[k] = p2[j];
                j++;
            }
            k++;
        }
        while (i<n1){
            arr[k] = p1[i];
            k++;
            i++;
        }
        while (j<n2){
            arr[k] = p2[j];
            k++;
            j++;
        }
        free(p1);
        free(p2);

}



void mergeSort(int *arr, int n){
int step = 0;
int position = 0;
for(step=1;step<n;step = step * 2){
    for(position=0;position<n-1;position = position + step *2){
        int mid = position + step - 1;
        int right = (position + step *2 - 1 < n -1)? position + step *2 -1: n-1 ;
        merge(arr,position,mid, right);

    }

}


}


int main(){
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    printf("after sort");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}