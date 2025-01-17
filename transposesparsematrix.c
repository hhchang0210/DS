/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <malloc.h>

#define MAX_TERMS 101
#define COL 6
#define ROW 6
typedef struct {
    int col;
    int row;
    int value;
    
} term ;
term a[MAX_TERMS];
term b[MAX_TERMS];
term d[MAX_TERMS];

int c[ROW][COL] = {
    {15,0,0,22,0,-15},
    {0,11,3,0,0,0},
    {0,0,0,-6,0,0},
    {0,0,0,0,0,0},
    {91,0,0,0,0,0},
    {0,0,28,0,0,0}
    
    
};

void CreatSParsrMatrix(int t1[][COL], term *t2){
    int index = 1;
    int row_max =0;
    int col_max = 0;
    for(int i = 0; i<ROW;i++){
        for(int j = 0; j<COL;j++){
            if(t1[i][j] != 0){
                //printf("t1=%d",t1[i][j]);
                t2[0].value++;
                t2[index].row = i;
                t2[index].col = j;
                t2[index].value = t1[i][j];
                index++;
                if (row_max < i ) row_max = i;
                if (col_max < j ) col_max = j;
                
                
            }
            
            
        }
        
    }
    t2[0].row = row_max;
    t2[0].col = col_max;
    
}

void TransposeSparseMatrix(term *t1,term *t2){
    // time complexity  = col * n ~= col * col * row
    int index = 1;
    for (int i = 0; i<=t1[0].col;i++){
        for (int j = 1; j<=t1[0].value;j++){
            if (t1[j].col == i){
                t2[index].row = t1[j].col;
                t2[index].col = t1[j].row;
                t2[index].value = t1[j].value;
                index++;
            }
            
            
        }
        
        
    }
    t2[0].row = t1[0].row;
    t2[0].col = t1[0].col;
    t2[0].value = t1[0].value;
    
}


void FastTranspose(term *t1, term *t2){
    // time complexity  = col + n + col + n ~= n = col*row
    int rowterms[COL], startingPos[COL];
    for (int i = 0; i<=t1[0].col;i++) rowterms[i] = 0;
    for (int i = 1; i<=t1[0].value;i++) rowterms[t1[i].col]++;
    startingPos[0] = 0;
    for (int i = 1; i<=t1[0].col;i++) startingPos[i] = rowterms[i-1] + startingPos[i-1];
    for (int i = 1; i<=t1[0].value; i++) {
        int j = startingPos[t1[i].col]++;
        t2[j+1].row = t1[i].col;
        t2[j+1].col = t1[i].row;
        t2[j+1].value = t1[i].value;
        //startingPos[t1[i].col]++;
        
    }
    t2[0].row = t1[0].row;
    t2[0].col = t1[0].col;
    t2[0].value = t1[0].value;
}

int main()
{

    CreatSParsrMatrix(c,a);
    for(int i=0;i<=a[0].value;i++){
        printf("row=%d col=%d value=%d\n", a[i].row,a[i].col, a[i].value);
        
    }
    printf("##########\n");
    //TransposeSparseMatrix(a,b);
    //for(int i=0;i<=b[0].value;i++){
    //    printf("row=%d col=%d value=%d\n", b[i].row,b[i].col, b[i].value);
        
    //}
    
    FastTranspose(a,d);
    for(int i=0;i<=d[0].value;i++){
        printf("row=%d col=%d value=%d\n", d[i].row,d[i].col, d[i].value);
        
    }



    return 0;
}