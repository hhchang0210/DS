#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

int main(){
    int array[N] = {0,9,8,7,6,5,4,3,2,1};
    for(int i=2;i<10;i++){
        int temp = array[i];
        array[0] = temp;
        int j = i;
        while(temp<array[j-1]){
            array[j] = array[j-1];
            j--; 

        }
        array[j] = temp;

    }
    for(int i=1;i<N;i++){
        printf("%d\n",array[i]);
    }

    return 0;
}