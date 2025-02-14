#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAZE_ROW 9
#define MAZE_COL 6

#define TRUE 1
#define FALSE 0
#define MAX 100
#define N 5

typedef struct {
    int row;
    int col;
    int index;
} element;

typedef struct {
    element data[MAX];
    int top;
    int bottom;
} elementStack;

//int top = -1;

typedef struct {
    int vertical;
    int horizon;
    int index;
} direction;

direction Direction[8] = {
{-1,0,0},
{-1,1,1},
{0,1,2},
{1,1,3},
{1,0,4},
{1,-1,5},
{0,-1,6},
{-1,-1,7},
};


int maze[MAZE_ROW][MAZE_COL] = {
    {0, 0, 0, 0, 0, 0}, 
    {1, 1, 1, 0, 1, 1}, 
    {1, 0, 0, 0, 0, 1},
    {0, 1, 1, 1, 1, 1}, 
    {1, 0, 0, 0, 0, 1}, 
    {1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 1}, 
    {0, 1, 1, 1, 1, 1}, 
    {1, 0, 0, 0, 0, 0}};
int checked[MAZE_ROW][MAZE_COL] = {0};

int Check(int row,int col, int direction, element *e, int pre_row, int pre_col){
    for(;direction<8;direction++){
        printf("checked\n");
        printf("Pre_row=%d\n",pre_row);
        printf("Pre_col=%d\n",pre_col);
        if (
            checked[row+Direction[direction].vertical][col+Direction[direction].horizon] == 1
        ){
            printf("checked\n");
            printf("Pre_row=%d\n",pre_row);
            printf("Pre_col=%d\n",pre_col);
            printf("row+Direction[direction].vertical=%d\n",row+Direction[direction].vertical);
            printf("col+Direction[direction].horizon=%d\n",col+Direction[direction].horizon);
            printf("direction=%d\n",direction);
            continue;
        }
        if ( (row+Direction[direction].vertical)>=0 && (row+Direction[direction].vertical)< MAZE_ROW &&
        (col+Direction[direction].horizon) >=0 && (col+Direction[direction].horizon)< MAZE_COL &&
        maze[row+Direction[direction].vertical][col+Direction[direction].horizon] == 0 
        ) {
            
            e->row = row;
            e->col = col;
            e->index = direction;
            printf("row+Direction[direction].vertical=%d\n",row+Direction[direction].vertical);
            printf("col+Direction[direction].horizon=%d\n",col+Direction[direction].horizon);
            printf("index=%d\n",e->index);
            printf("maze=%d\n",maze[row+Direction[direction].vertical][col+Direction[direction].horizon]);
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

void PrintChecked(int p[][MAZE_COL]){
    for(int i=0;i<MAZE_ROW;i++){
        for(int j=0;j<MAZE_COL;j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

void PrintStack(elementStack *stack){
    printf("prinfstack");
    for(int i = 0; i<=stack->top;i++){
        printf("row=%d  ",stack->data[i].row);
        printf("col=%d\n",stack->data[i].col);
        
    }
}


int main (int argc, char *argv[]) {
    //printf("%d\n",Direction[0].vertical);
    int global = 1;
    //Knight[0][0] = global;
    //global++;
    int row = 0;
    int col = 0;
    int index = 0;
    int pre_row = -1;
    int pre_col = -1;

    elementStack stack;
    element e;
    stack.top = -1;
    stack.bottom = 0;


                
    while(1){     
       
        //PrintKnight(Knight);
        if (Check(row, col, index,&e, pre_row, pre_col) != -1) {

            Push(&stack, e);
            checked[row][col] = 1;
            pre_row = row;
            pre_col = col;
            //Knight[row][col] = global++;
            row = row+Direction[e.index].vertical;
            col = col+Direction[e.index].horizon;
            index = 0;
            //PrintStack(&stack);
            printf("Pre_row=%d\n",pre_row);
            printf("Pre_col=%d\n",pre_col);
            printf("row=%d\n",row);
            printf("col=%d\n",col);
            printf("stack.top=%d\n",stack.top);
            getchar();
            if (row == MAZE_ROW - 1 && col == MAZE_COL -1) {
                printf("break the maze\n");
                PrintChecked(checked);
                printf("########\n");
                PrintChecked(maze);
                PrintStack(&stack);
                break;
            }    
    }
    else{
        printf("else");
        printf("row=%d\n",row);
        printf("col=%d\n",col);
        printf("stack.top=%d\n",stack.top);

        
        maze[row][col] = 2;
        checked[row][col] = 0;
        

        if (Pop(&stack, &e) != -1){
            row = e.row;
            col = e.col;
            index = e.index+1;
            //printf("nono\n");
            //printf("row=%d\n",row);
            //printf("col=%d\n",col);
            //printf("index=%d\n",index);
            checked[row][col] = 0;
            PrintChecked(checked);
        }
        else{
            printf("no solution\n");
            break;
        }
    }


    }

    return 0;
    }