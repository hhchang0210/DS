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
   treepointer lchild,rchild,parent; /* ���Һ���ָ�� */
}BiTNode;

bool initroot = false; 
treepointer lastnode;
treepointer *parent;

int createTree(treepointer *p) {
    //BiTNode *node;
    //treepointer node;
    //node = (BiTNode *)malloc(sizeof(BiTNode));
    int c;
    scanf("%d",&c);
    
    if (c==-1) *p=NULL; 
    else if (!initroot)
    {
        initroot = true;
        *p = malloc(sizeof(BiTNode));
        (*p)->data = c;
        (*p)->parent = NULL;
        parent = p;
        //printf("%c\n",(*p)->data);
        createTree( &(*p)->lchild );
        createTree( &(*p)->rchild );
      
    }
    
    else {
        *p = malloc(sizeof(BiTNode));
        (*p)->data = c;
        (*p)->parent = *parent;
        parent = p;
        //printf("%c\n",(*p)->data);
        createTree( &(*p)->lchild );
        createTree( &(*p)->rchild );
    
    }
    
    return 1;
}

treepointer _createNode(treepointer p, int c, treepointer root) {
    if (!p) {
        //printf("p -= null\n");
        treepointer temp = malloc(sizeof(BiTNode));
        temp->data = c;
        temp->lchild = NULL;
        temp->rchild = NULL;
        temp->parent = root;
        return temp;
    }
    if (c < p->data){
        printf("insert Node left\n");
        p->lchild = _createNode(p->lchild,c,p);
    }
    else if (c > p->data)
    {
        printf("insert Node right\n");
        p->rchild = _createNode(p->rchild,c,p);
    }
    
    return p;

}

treepointer insertNode(treepointer p){

    int c;
    printf("insert number\n");
    scanf("%d",&c);
    while (c != -1){   
        p = _createNode(p,c,NULL);
        scanf("%d",&c);
    }
    return p;
    
}

void inorder(treepointer ptr){

    if(ptr) {
        inorder(ptr->lchild);
        printf("%c\n",ptr->data);
        inorder(ptr->rchild);
    }

}

void postorder(treepointer ptr){

    if(ptr) {
        postorder(ptr->lchild); 
        postorder(ptr->rchild);
        printf("%c\n",ptr->data);
    }

}

void preorder(treepointer ptr){

    if(ptr) {
        //printf("hhh\n");
        printf("%d\n",ptr->data);
        printf("/\n");
        preorder(ptr->lchild);
        printf("\\"); 
        preorder(ptr->rchild);
        
    }

}









void preorderTraversalWithLevel(treepointer root, int level) {
    if (root != NULL) {
        for (int i = 0; i < level; i++) {
            printf("  "); // 使用空格縮排表示階層
        }
        printf("%d\n", root->data);
        preorderTraversalWithLevel(root->lchild, level + 1);
        preorderTraversalWithLevel(root->rchild, level + 1);
    }
}

treepointer findMax(treepointer node) {
    treepointer current = node;
    while (current && current->rchild != NULL) {
        current = current->rchild;
    }
    return current;
}


treepointer deleteNode(treepointer p, int c){
    printf("starting delete\n");
    if(!p) {
        printf("no such data\n");
        return p;
    }
    if (c < p->data){
        p->lchild = deleteNode(p->lchild, c);
    }
    else if (c > p->data){
        p->rchild = deleteNode(p->rchild, c);
    }
    else{
        if (p->lchild == NULL){
            treepointer temp = p->rchild;
            if (p->parent != NULL){
                if(p->parent->lchild == p){
                    p->parent->lchild = temp;                   
                }
                else{
                    p->parent->rchild = temp;
                }
            }
            return temp;
        }
        else if (p->rchild == NULL){
            treepointer temp = p->lchild;
            if (p->parent != NULL){
                if(p->parent->lchild == p){
                    p->parent->lchild = temp;                   
                }
                else{
                    p->parent->rchild = temp;
                }
            }
            return temp;
        }
        treepointer temp = findMax(p->lchild);
        p->data = temp->data;
        p->lchild = deleteNode(p->lchild, temp->data);


    }
    return p;
        
    
}


treepointer _searchBST(treepointer p, int c){
    //treepointer parent;
    if(!p){
        printf("no such number=%d\n",c);
        //printf("insert the number\n");
        //insertNode(p,c,root);

    }
    
    if (c < p->data){
        
        p->lchild = _searchBST(p->lchild,c);
    }
    else if (c > p->data)
    {
        
        printf("serch right\n");
        p->rchild = _searchBST(p->rchild,c);
    }
    else{
        printf("bingo\n");
        printf("data=%d\n",p->data);
        //p = deleteNode(p,c);
        
    }
    return p;
}

treepointer searchBST(treepointer p){
    printf("enter number\n");
    int c;
    scanf("%d",&c);
    while(c != -1){
        _searchBST(p,c);
        printf("enter number\n");
        scanf("%d",&c);
    }
    return p;


}


int main (int argc, char *argv[]) {
    treepointer ROOT;
    printf("create tree\n");
    createTree(&ROOT);
    preorder(ROOT);
    printf("insert node");
    insertNode(ROOT);
    printf("after insert\n");
    preorder(ROOT);
    printf("searchBST");
    searchBST(ROOT);
    ROOT = deleteNode(ROOT,100);
    printf("after delete\n");
    preorder(ROOT);
    //printf("after delete\n");
    //preorder(ROOT);
    //printf("last = %d\n",lastnode->data);
    /*
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
    */


    
    return 0;
}