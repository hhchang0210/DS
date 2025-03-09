#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

void _qsort(int *arr, int left, int right){
    if (left < right){
        int i=left, j=right;
        int pivot = arr[left];
        //int pivot_position = left;
        i++;
        while (i<j)
        {
            while (arr[i] < pivot){
                i++;
            }
            while(arr[j] > pivot){
                j--;
            }
            if(i<j){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }

        }
        int temp = arr[j];
        arr[j] = arr[left];
        arr[left] = temp;
        
        _qsort(arr,left,j-1);
        _qsort(arr,j+1,right);
        
    }




}

int main(){
    int array[N] = {0,9,8,7,6,5,4,3,2,1};
    _qsort(array,0,N-1);
    for(int i=0;i<N;i++){
        printf("%d\n",array[i]);
    }

    return 0;
}