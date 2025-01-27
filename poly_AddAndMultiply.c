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

typedef struct listNode* listPointer;
typedef struct listNode {
    int e;
    int c;
    listPointer next;
    
} NODE;

listPointer createNode(int s,int t) {
    
    listPointer p = NULL;
    MALLOC(p,sizeof(*p));
    p->c = s;
    p->e = t;
    p->next = NULL;
    //printf("p.c=%d p.e=%d\n",p->c, p->e);
    return p;
    
}   

listPointer AddNode(listPointer p, listPointer next) {
    listPointer t = p;
    while(p->next != NULL) {
        p = p->next;
        
    }
    p->next = next;

    return t;
    
}  

listPointer InsertNode(listPointer p, listPointer next) {
    listPointer temp = p;
    listPointer m;
    while (temp != NULL)
    {
        if (temp->e < next->e) {
        
        next->next = temp;
        temp = next;
        return p;
        }
        else if (temp->e > next->e) {
            m = temp;
            temp = temp->next;
          
        }
        else {
            temp->c = temp->c + next->c;
            return p;

        }
    

    }
    m->next = next;
    return p;
}   


void PrintNode( listPointer p){
    
    while(p != NULL){
        printf("c=%d e=%d\n", p->c,p->e);
        p = p->next;
        
        
    }
    
}

listPointer AddPoly(listPointer A, listPointer B){
    listPointer C = NULL;
    while (A && B ) {
        if (A->e == B->e)
        {
         // printf("test");
        if (C)
        {
            C = InsertNode(C, createNode(A->c+B->c, A->e));
        }
        else C = createNode(A->c+B->c, A->e);
        A = A->next;
        B = B->next;
        printf("equal\n");
        printf("A.c=%d A.e=%d\n",A->c, A->e);
        printf("B.c=%d B.e=%d\n",B->c, B->e);
        printf("printNode A\n");
        PrintNode(A);
        printf("printNode C\n");
        PrintNode(C);
        
        }
        else if (A->e < B->e){
            listPointer t = B;
            B = B->next;
            t->next = NULL;
            if (C) {
                C = AddNode(C, t);

            }
            else C = createNode(t->c,t->e);
            
            printf("B>A\n");
            printf("A.c=%d A.e=%d\n",A->c, A->e);
            //printf("B.c=%d B.e=%d\n",B->c, B->e);
            if (!B) printf("B is NULL\n");
            printf("printNode A\n");
            PrintNode(A);
            printf("printNode C\n");
            PrintNode(C);
            printf("##end\n");
            printf("test\n");
        }
        else {
            listPointer t = A;
            A = A->next;
            t->next = NULL;
            printf("before add node printNode C\n");
            //PrintNode(C);
            if (C) {
                C = AddNode(C, t);

            }
            else C = createNode(t->c,t->e);
            
            //printf("A>B\n");
            //printf("A.c=%d A.e=%d\n",A->c, A->e);
            //printf("B.c=%d B.e=%d\n",B->c, B->e);
            //printf("printNode A\n");
            //PrintNode(A);
            //printf("printNode C\n");
            //PrintNode(C);
        }
    
    }
    printf("quite while\n");
    for(;A;A = A->next) { 
        printf("A.c=%d A.e=%d\n",A->c, A->e);
        printf("A loop\n");
        C = AddNode(C,A);
    }
    for(;B;B = B->next) {
        printf("B loop\n");
        printf("B.c=%d B.e=%d\n",B->c, B->e);
        C = AddNode(C,B);
    }
    return C;
}

listPointer Multiply(listPointer A, listPointer B){
    listPointer temp1, temp2, C1=NULL, C2=NULL, C=NULL;
    //temp1 = A;
    //temp2 = B;
    int count = 0;
    while(B) {
        C2 = NULL;
        temp1 = A;
        while (temp1){
            int i = temp1->c * B->c;
            int j = temp1->e + B->e;
            if (count == 0){
                if (!C1){

                C1 = createNode(i,j);
            }
                else
                {
                C1 = AddNode(C1, createNode(i,j));
                }
            }
            else {
                if (!C2) {
                    C2 = createNode(i,j);

                }
                else{
                    C2 = AddNode(C2, createNode(i,j));
                }
            }
            temp1 = temp1->next;
        }
        printf("##if C1\n");
        PrintNode(C1);
        if(C2){
            printf("##if C2\n");
            PrintNode(C2);

        }
        if (C1 && C2) {
            C = AddPoly(C1, C2);
            printf("##if C\n");
            PrintNode(C);
        }
        count++;
        B = B->next;


    }
    if (!C2) {

        C = C1;
    }
    return C;


}

int main()
{
    listPointer A, B,C;
    A = createNode(3,14);
    //PrintNode(A);
    A = InsertNode(A, createNode(2,8));
    A = InsertNode(A, createNode(1,0));
    PrintNode(A);
    //A = InsertNode(A, createNode(7,8));
    //PrintNode(A);
    B = createNode(8,14);
    B = InsertNode(B,createNode(-3,10));
    //B = InsertNode(B, createNode(10,6));
    PrintNode(B);
    //C = AddPoly(A,B);
    //printf("final C\n");
    //PrintNode(C);
    C = Multiply(A,B);
    printf("final C\n");
    PrintNode(C);
    /** 
    listPointer first = createNode(10);
    listPointer next =  createNode(20);
    first = AddNode(first, next);
    PrintNode(first);
    first = InsertNode(first, createNode(15));
    PrintNode(first);
    first = InsertNode(first, createNode(5));
    PrintNode(first);
    first = InsertNode(first, createNode(50));
    PrintNode(first);
    //first = DeleteNode(first, createNode(10));
    //PrintNode(first);
    //first = DeleteNode(first, createNode(5));
    //PrintNode(first);
    //first = DeleteNode(first, createNode(50));
    //PrintNode(first);
    first = ReverseList(first);
    PrintNode(first);
    **/
    return 0;
}