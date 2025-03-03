#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BiTNode *treepointer;

typedef struct BiTNode {
    int data;
    int height;
    treepointer lchild, rchild, parent;
} BiTNode;

bool initroot = false;

// 建立新節點
treepointer createNode(int data) {
    treepointer newNode = (treepointer)malloc(sizeof(BiTNode));
    if (newNode == NULL) {
        fprintf(stderr, "記憶體分配失敗\n");
        exit(1);
    }
    newNode->data = data;
    newNode->height = 0;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->parent = NULL;
    return newNode;
}

// 尋找最小節點
treepointer findMin(treepointer node) {
    treepointer current = node;
    while (current && current->lchild != NULL) {
        current = current->lchild;
    }
    return current;
}

// 刪除節點
treepointer deleteNode(treepointer root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->lchild = deleteNode(root->lchild, data);
    } else if (data > root->data) {
        root->rchild = deleteNode(root->rchild, data);
    } else {
        // 找到要刪除的節點
        if (root->lchild == NULL) {
            treepointer temp = root->rchild;
            free(root);
            return temp;
        } else if (root->rchild == NULL) {
            treepointer temp = root->lchild;
            free(root);
            return temp;
        }

        // 節點有兩個子節點，找到右子樹的最小節點
        treepointer temp = findMin(root->rchild);
        root->data = temp->data;
        root->rchild = deleteNode(root->rchild, temp->data);
    }

    return root;
}

// 前序遍歷二元樹
void preorder(treepointer ptr) {
    if (ptr) {
        printf("%d\n", ptr->data);
        printf("/\n");
        preorder(ptr->lchild);
        printf("\\\n");
        preorder(ptr->rchild);
    }
}

// 建立二元樹 (根據輸入建立)
int createTree(treepointer *p, int c) {
    if (!initroot) {
        initroot = true;
        *p = createNode(c);
        printf("input -1\n");
        createTree(&(*p)->lchild, c);
        printf("input -1\n");
        createTree(&(*p)->rchild, c);
    } else {
        int t;
        scanf("%d", &t);
        if (t == -1) *p = NULL;
    }
    return 1;
}

// 插入節點 (重複則刪除)
treepointer _createNode(treepointer p, int c, treepointer root) {
    if (!p) {
        treepointer temp = createNode(c);
        temp->parent = root;
        return temp;
    }
    if (c < p->data) {
        printf("insert Node left\n");
        p->lchild = _createNode(p->lchild, c, p);
    } else if (c > p->data) {
        printf("insert Node right\n");
        p->rchild = _createNode(p->rchild, c, p);
    } else {
        // 重複，刪除節點
        printf("find the node=%d\n", p->data);
        return deleteNode(p, c); // 回傳新的子樹根節點
    }
    return p;
}

treepointer insertNode(treepointer p, int c) {
    return _createNode(p, c, NULL);
}

int main(int argc, char *argv[]) {
    treepointer ROOT = NULL;
    int c;
    scanf("%d", &c);
    while (c != -1) {
        if (ROOT == NULL) {
            printf("create tree\n");
            createTree(&ROOT, c);
            printf("input number\n");
            scanf("%d", &c);
        } else {
            printf("insert node in main\n");
            ROOT = insertNode(ROOT, c); // 更新 ROOT 指標
            printf("root preorder\n");
            preorder(ROOT);
            printf("input number\n");
            scanf("%d", &c);
        }
    }

    preorder(ROOT);
    return 0;
}