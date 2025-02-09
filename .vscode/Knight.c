#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>


#define TRUE 1
#define FALSE 0
#define MAX 100
#define N 6

typedef struct {
    int row;
    int col;
    int index;
} element;

typedef struct {
    element data[MAX];
    int top;
} elementStack;

//int top = -1;

typedef struct {
    int vertical;
    int horizon;
    int index;
} direction;

direction Direction[8] = {
{-2,1,0},
{-1,2,1},
{1,2,2},
{2,1,3},
{2,-1,4},
{1,-2,5},
{-1,-2,6},
{-2,-1,7},
};

int Knight[N][N] = {0};
//int global = 1;
int Check(int row,int col, int direction, element *e){
    for(;direction<8;direction++){
        //printf("check row=%d\n",row);
        //printf("check col=%d\n",col);
        if ( (row+Direction[direction].vertical)>=0 && (row+Direction[direction].vertical)<N &&
            (col+Direction[direction].horizon) >=0 && (col+Direction[direction].horizon)<N &&
            Knight[row+Direction[direction].vertical][col+Direction[direction].horizon] == 0 
            ) {
            e->row = row;
            e->col = col;
            e->index = direction;
            //printf("row+Direction[direction].vertical=%d\n",row+Direction[direction].vertical);
            //printf("col+Direction[direction].horizon%d\n",col+Direction[direction].horizon);
            //printf("index=%d\n",e->index);
            //printf("knight=%d\n",Knight[row+Direction[direction].vertical][col+Direction[direction].horizon]);
            return direction;
        }
        
    }
    return -1;
}

int Push(elementStack *S,element e){
    if (S->top == MAX -1){
        return -1;
    }
    else {
        S->top++;
        S->data[S->top] = e;
        return 1;
        
    }

}

int Pop(elementStack *S, element *e){
    if(S->top == -1){
        return -1;
    }
    else {
        *e= S->data[S->top];
        S->top--;
        return 1;

    }

}

void PrintKnight(int p[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

void PrintStack(elementStack *S){
    printf("stack top=%d\n",S->top);
}

int main (int argc, char *argv[]) {
    //printf("%d\n",Direction[0].vertical);
    //Knight[0][0] = global;
    //global++;
    //int row = 0;
    //int col = 0;
    //int index = 0;

    //printf("few\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int row = i;
            int col = j;
            int index = 0;
            //Knight[row][col]=0;
            int global = 1;    
            printf("row=%d\n",row);
            printf("col=%d\n",col);   
            for (int s = 0; s < N; s++)
            {
                for (int t = 0; t < N; t++) {
                    Knight[s][t] = 0;
                }
            }
            elementStack stack;
            element e;
            stack.top = -1;

                
    while(1){     
          //printf("entering while\n");
          //PrintKnight(Knight);
          if (Check(row, col, index,&e) != -1) {

            Push(&stack, e);
            Knight[row][col] = global++;
            row = row+Direction[e.index].vertical;
            col = col+Direction[e.index].horizon;
            index = 0;
            //PrintStack(&stack);
            //printf("row=%d\n",row);
            //printf("col=%d\n",col);
            //printf("knigh=%d\n",Knight[row][col]);
            //getch();
            if (stack.top == N*N-2){
                printf("solution\n");
                Knight[row][col] = global;
                PrintKnight(Knight);

                break;
            }
        }
        else{
            global--;
            Knight[row][col] = 0;
            if (Pop(&stack, &e) != -1){
                row = e.row;
                col = e.col;
                index = e.index+1;
                //printf("nono\n");
                //printf("row=%d\n",row);
                //printf("col=%d\n",col);
                //printf("index=%d\n",index);
            }
            else{
                printf("no solution\n");
                break;
            }
        }


    }
}
}  
    return 0;
}