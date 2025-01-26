/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define MALLOC(p,s) \
    if (! ( (p) = malloc(s))) {\
        fprintf(stderr, "insufficient memoty");\
        exit(EXIT_FAILURE);\
    }
#define MAX_SIZE 12
#define TRUE 1
#define FALSE 0

typedef struct Node* NodePointer;
typedef struct Node {
    int data;
    NodePointer next;
    
} NODE;

void PrintNode( NodePointer p){
    printf("#########\n");
    while(p != NULL){
        
        printf("%d ", p->data);
        p = p->next;
        
        
    }
    printf("\n");
}

int main()
{
    NodePointer arr[MAX_SIZE];
    int out[MAX_SIZE];
    NodePointer x,y,top;
    int p,q;
    int j,k,n;
    for(int i =0;i<MAX_SIZE;i++){
        arr[i] = NULL;
        out[i] = TRUE;
        
    }
    for (int i =0;i<9;i++){
    scanf("%d %d", &p, &q);
    fflush(stdout);
    //printf("%d %d\n", p, q);
    //fflush(stdout);
    NodePointer temp1;
    MALLOC(temp1, sizeof(*temp1));
    temp1->data = q;
    //printf("%d\n", temp1->data); 
    temp1->next = arr[p];
    arr[p] = temp1;
    //printf("%d\n", temp1->data);  
    
    NodePointer temp2;
    MALLOC(temp2, sizeof(*temp2));
    temp2->data = p;
    temp2->next = arr[q];
    arr[q] = temp2;
        
    }
    //for (int i = 0; i<MAX_SIZE;i++){
    //    PrintNode(arr[i]);
    //}
    
    for (int i = 0; i<MAX_SIZE;i++){
        if(out[i]){
            printf("\nNew calass: %5d",i);
            out[i] = FALSE;
            x = arr[i];
            top = NULL;
            for(;;){
                while(x) {
                    j = x->data;
                    if(out[j]){
                        // if out[j] is true -> reverse the list of arr[] -> like stack (push)
                        printf("%5d",j);
                        out[j] = FALSE;
                        y = x->next;
                        x->next = top;
                        top = x;
                        x = y;
                        printf("\n###top=%d###\n", top->data);
                        if(x == NULL) printf("x=NULL");
                        else printf("\n### x=%d###\n", x->data);
                    }
                    else {
                        // if out[j] 已經被走過, FALSE, x 就跳到下一個, 但不動 top (不動 stack)
                        x = x->next;
                        if(x == NULL) printf("else x = NULL");
                        else printf("\n!!! x=%d!!!\n", x->data);
                        if(top == NULL) printf("else top = NULL");
                        else printf("\n!!!top=%d!!!\n",top->data);
                    }
                    
                    
                }
                if(!top) break;
                //getchar();
                x = arr[top->data];
                printf("\n###top 2 = %d###\n", top->data);
                top = top->next; // pop from the stack (top is the pointer of the stack)
                //for example 先走完 arr[0] 裡面的 11,4, 然後再去走 arr[4] 裡面的 7, 0, 再去走 arr[7] 裡的4
                //然後再 pop top == 11, 再走 arr[11]
                if(top == NULL) printf("\n### top3 = NULL");
                else printf("\n### top 3=%d###\n",top->data);
                
            }
            
            
            
        }
        
    }
    
    
    return 0;
}


