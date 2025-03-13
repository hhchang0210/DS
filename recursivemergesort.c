#include <stdio.h>
#include <stdlib.h>

// 合併兩個已排序的子陣列
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 建立臨時陣列
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // 將資料複製到臨時陣列 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合併臨時陣列到 arr[left...right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 複製 L[] 中剩餘的元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 複製 R[] 中剩餘的元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// 迭代式合併排序
void mergeSort(int arr[], int left, int right) {
    if (left < right){

        int mid = (left + right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr, mid+1, right);
        merge(arr,left,mid, right);

    }

}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0,n-1);

    printf("after sort：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}