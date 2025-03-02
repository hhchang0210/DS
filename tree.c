#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BiTNode *treepointer;

typedef struct BiTNode  /* ���ṹ */
{
   int data;	
   int height;
   treepointer lchild,rchild; /* ���Һ���ָ�� */
}BiTNode;


treepointer newTreeNode(int val) {
    BiTNode *node;
    //treepointer node;
    node = (BiTNode *)malloc(sizeof(BiTNode));
    node->data = val;
    node->height = 0;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

void inorder(treepointer ptr){

    if(ptr) {
        inorder(ptr->lchild);
        printf("%d\n",ptr->data);
        inorder(ptr->rchild);
    }

}

void postorder(treepointer ptr){

    if(ptr) {
        postorder(ptr->lchild); 
        postorder(ptr->rchild);
        printf("%d\n",ptr->data);
    }

}

void preorder(treepointer ptr){

    if(ptr) {
        printf("%d\n",ptr->data);
        preorder(ptr->lchild); 
        preorder(ptr->rchild);
        
    }

}



int main (int argc, char *argv[]) {
    treepointer ROOT;
    //MALLOC(ROOT, sizeof(*ROOT));
	treepointer n1 = newTreeNode(1);
    treepointer n2 = newTreeNode(2);
    treepointer n3 = newTreeNode(3);
    treepointer n4 = newTreeNode(4);
    treepointer n5 = newTreeNode(5);

	n1->lchild = n2;
    n1->rchild = n3;
    n2->lchild = n4;
    n2->rchild = n5;
    printf("inorder\n");
    inorder(n1);
    printf("postorder\n");
    postorder(n1);
    printf("preorder\n");
    preorder(n1);



    
    return 0;
}