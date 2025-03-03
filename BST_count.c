#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BiTNode *treepointer;

typedef struct BiTNode  
{
   int data;	
   int height;
   treepointer lchild,rchild,parent; 
}BiTNode;

bool initroot = false; 
treepointer lastnode;
treepointer *parent, TOP;

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

treepointer findMax(treepointer node) {
    treepointer current = node;
    while (current && current->rchild != NULL) {
        current = current->rchild;
    }
    return current;
}




treepointer deleteNode(treepointer p, int c){
    printf("starting delete\n");

if (p == NULL) {
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
        printf("p->lchild == NULL\n");
        treepointer temp = p->rchild;
        
        free(p);
        return temp;
    }
    else if (p->rchild == NULL){
        printf("p->rchild == NULL\n");
        treepointer temp = p->lchild;
       
        free(p);
        return temp;
    }
    treepointer temp = findMax(p->lchild);
    p->data = temp->data;
    p->lchild = deleteNode(p->lchild, temp->data);


}

    return p;
        
    
}



int createTree(treepointer *p, int c) {
    //BiTNode *node;
    //treepointer node;
    //node = (BiTNode *)malloc(sizeof(BiTNode));
  
    if (!initroot)
    {
        initroot = true;
        *p = malloc(sizeof(BiTNode));
        (*p)->data = c;
        (*p)->parent = NULL;
        //parent = p;
        //printf("%c\n",(*p)->data);
        printf("input -1\n");
        createTree( &(*p)->lchild,c );
        printf("input -1\n");
        createTree( &(*p)->rchild,c );
      
    }
    else{
    int t;
    scanf("%d",&t);
    
    if (t==-1) *p=NULL; 
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
    else {
        //delete node
        printf("find the node=%d\n",p->data);
        return deleteNode(p,c);

    }
    
    return p;

}

treepointer insertNode(treepointer p, int c){

  
    p = _createNode(p,c,NULL);
        
    return p;
    
}


int main (int argc, char *argv[]) {
    treepointer ROOT = NULL;
    int c;
    scanf("%d",&c);
    while (c != -1){
        if (ROOT == NULL){
            printf("create tree\n");
            createTree(&ROOT,c);
            printf("input number\n");
            scanf("%d",&c);
            
        }
        else{
            printf("insert node in main\n");
            ROOT = insertNode(ROOT,c);
            printf("root preorder\n");
            preorder(ROOT);
            printf("input number\n");
            scanf("%d",&c);
        }
    }
    
    
    

    preorder(ROOT);
    //printf("insert node");
    //insertNode(ROOT);
    //printf("after insert\n");
    //preorder(ROOT);
    //printf("searchBST");
    //searchBST(ROOT);
    //ROOT = deleteNode(ROOT,100);
    //printf("after delete\n");
    //preorder(ROOT);
    
    return 0;
}