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
    int data;
    listPointer next;
    
} NODE;

listPointer createNode(int d) {
    
    listPointer p = NULL;
    MALLOC(p,sizeof(*p));
    p->data = d;
    p->next = NULL;
    return p;
    
}   

listPointer AddNode(listPointer p, listPointer next) {
    
    while(p->next != NULL) {
        p = p->next;
        
    }
    p->next = next;

    return p;
    
}  

listPointer InsertNode(listPointer p, listPointer next) {
    listPointer temp = p;
    if (p->data > next->data) {
        
        next->next = p;
        p = next;
        return p;
        
    }
    else {
        while(temp->next != NULL) {
            listPointer m = temp;
            temp = temp->next;
            if (temp->data > next->data){
                next->next = temp;
                m->next = next;
                return p;
                
            }
        
        
        }
        temp->next = next;
        return p;
        
    }
    
    
    
    
}   


void PrintNode( listPointer p){
    
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
        
        
    }
    
}


listPointer DeleteNode( listPointer p, listPointer node){
    listPointer temp = p;
    if (temp->data == node->data) {
        p = temp->next;
        free(temp);
        return p;
    }
    else{
        while(temp->next != NULL){
            listPointer m = temp;
            temp = temp->next;
            if(temp->data == node->data){
                m->next = temp->next;
                temp->next = NULL;
                free(temp);
                return p;
                
            
                
            }
            
        }
        
        
        
    }
    return p;
    
}

listPointer ReverseList(listPointer p){
    //use three pointer to reverse the list
    listPointer m = p;
    listPointer front = p->next;
    listPointer back;
    while(m->next != NULL){
        if (m == p) {
            m->next = NULL;
            back = m;
            m = front;
            front = front->next;
            
            
        }
        else {
            m->next = back;
            back = m;
            m = front;
            front = front->next;
            
        }
        
        
        
        
    }
    m->next = back;
    return m;
    
}

int main()
{
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
    return 0;
}