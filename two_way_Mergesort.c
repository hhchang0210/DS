#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4
#define M 4

int main(){
    int merge1[N] = {1,5,26,77};
    int merge2[M] = {11,15,59,61};
    int index1 = 0;
    int index2 = 0;
    int array[N+M] = {0};
    int index = 0;
    for(int i=0;i<N;i++){
        for (int j=index2;j<M;j++){
            if (merge1[i]<merge2[j]){
                array[index++] = merge1[i];
                index1++;
                break;
            }
            else{
                array[index++] = merge2[j];
                index2++;
            }
        }
    }

    for (; index1<N; index1++)
    {
        array[index++] = merge1[index1];
    }
    for (; index2<M; index2++)
    {
        array[index++] = merge2[index2];
    }
    for (int i=0; i<N+M; i++)
    {
        printf("%d\n",array[i]);
    }
    
    return 0;
}