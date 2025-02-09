#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *Linklist; /* ����LinkList */

Status Getelem(Linklist l,int i,ElemType &e){
    int j=1;
    Linklist p;
    p=l->next;
    while(j<i&&p){
        p=p->next;
        j++;

    }
    if(j>i||!p)
    {
        return ERROR;
    }
    e=p->data;
    return OK;

}

Status Insertelem(int i,ElemType e,Linklist l)
{
    int j=1;
    Linklist p,s;
    p=l;
    while(j<i&&p)
    {
        p=p->next;
        j++;
    }
    if(j>i||!p)
        return ERROR;
    
        s=(Linklist)malloc(sizeof(Node));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return OK;
}
Status Delelem(Linklist l,int i,ElemType &e){
    int j=1;
    Linklist p,s;
    p=l;
    while(j<i&&p)
    {
        p=p->next;
        j++;
    }
    if(j>i||!p)
        return ERROR;
    s=p->next;p->next=s->next;
    e=s->data;free(s);
    return OK;
}
void CreateListhead(Linklist *l,int n){
    int i;
    Linklist p;
    *l=(Linklist)malloc(sizeof(Node));
    srand(time(0));
    (*l)->next=NULL;
    for(i-0;i<n;i++){
        p=(Linklist)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->next=(*l)->next;
        (*l)->next=p;
    }
}
void CreateListtail(Linklist *l,int n){
    int i;
    Linklist p,r;
    *l=(Linklist)malloc(sizeof(Node));
    srand(time(0));
    r=*l;
    for(i-0;i<n;i++){
        p=(Linklist)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->next=p;
        r=p;
    }
    r->next=NULL;
}
Status Dellist(Linklist& l){
    Linklist p,q;
    //p=(Linklist)malloc(sizeof(Node));
    p=l->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    l->next=NULL;
    return OK;
}


int main(){


    Linklist p,s;
    p->data=88;
   //s->next=p->next;
    //p->next=s;

    printf("test OK!������\n");
    return 0;
}
