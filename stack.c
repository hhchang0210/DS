#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int top = -1;

#define MALLOC(p,s) \
    if (! ( (p) = malloc(s))) {\
        fprintf(stderr, "insufficient memoty");\
        exit(EXIT_FAILURE);\
    }

bool StackFull(){
    return top == MAX-1;

}

void Push(int *arr,int num){
    if (!StackFull()){
        top++;
        arr[top] = num;

    }
    else {
        printf("Stack is full");
        
    }

}
void printStack(int *arr){
    for(int i = 0; i<=top;i++){
        printf("stack[%d]=%d\n",i, arr[i]);
    }
}

bool isEmpty(int *arr){
    return top == -1;

}

int Pop(int *arr){
    if (!isEmpty(arr)) {
        int i = arr[top];
        top--;
        printf("pop = %d\n", i);
        return i;

    }
    else{
        printf("stack is empty");
    }

}

int main(){

    int stack[MAX] = {0};
    Push(stack, 10);
    Push(stack, 20);
    Push(stack, 30);
    printStack(stack);
    Pop(stack);
    printStack(stack);

    return 0;
}