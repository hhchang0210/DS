#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

void preorder(int *p, int i){
    if(i<N){
        printf("%d\n",p[i]);
        preorder(p, i*2+1);
        preorder(p,i*2+2);
    }
}

void inorder(int *p, int i){
    if(i<N){
        
        inorder(p, i*2+1);
        printf("%d\n",p[i]);
        inorder(p,i*2+2);
    }
}

int main (int argc, char *argv[]) {
    int arr[N] = {1,2,3,4,5};
    printf("preorder\n");
    preorder(arr, 0);
    printf("inorder\n");
    inorder(arr, 0);
    return 0;
}