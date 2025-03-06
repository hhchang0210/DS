#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10
int number = 0;

void pushElement(int *array){
    number++;
    int i;
    while(number<N){
        int temp = number;
        printf("input number\n");
        scanf("%d",&i);
        if (number==1){
            array[number] = i;
        }
        else if (i == -1)
        {
            printf("i=-1\n");
            break;
        }
        
        else{
            while(array[temp/2]<i && temp/2 > 0){
                array[temp] = array[temp/2];
                temp = temp/2;
            }
            array[temp] = i;
        }
        number++;
        printf("number=%d\n",number);

    }
}

void printPQ(int *array){
    for(int i=0;i<number;i++){
        printf("i=%d, PQ[i]=%d\n",i,array[i]);
        printf("number=%d\n",number);
    }
}

void popMax(int *array){
    
    printf("array[1]=%d\n",array[1]);
    array[1]=array[number];
    number--;
    int i=1;
    while(i*2<number){
        if(array[i*2]>array[i*2+1] && array[i]<array[i*2]){
            int temp = array[i*2];
            array[i*2] = array[i];
            array[i] = temp;
            i=i*2;
        }
        else if (array[i*2]<array[i*2+1] && array[i]<array[i*2+1]){
            int temp = array[i*2+1];
            array[i*2+1] = array[i];
            array[i] = temp;
            i=i*2+1;
        }
        else if (array[i]>array[i*2] && array[i]>array[i*2+1]){
            break;
        }
        
        
        
    }


}

int main(){
    int PQ[N] = {0};
    pushElement(PQ);
    printPQ(PQ);
    popMax(PQ);
    printf("after popMax\n");
    printPQ(PQ);
    return 0;
}