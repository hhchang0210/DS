#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>


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
int total = 0;


void print_Knight(int p[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}



int Check(int arr[][5], int row, int col, int step){
    
    if ( row >=0 && row<N &&  col >=0 && col<N &&      Knight[row][col] == 0             )
             {
            arr[row][col] = step;
            if (step == N*N) {
                total++;
                printf("total=%d\n",total);
                print_Knight(arr);
                getchar();
            }
        Check(arr, row - 2, col - 1, step + 1);
        Check(arr, row - 1, col - 2, step + 1);
        Check(arr, row + 1, col - 2, step + 1);
        Check(arr, row + 2, col - 1, step + 1);
        Check(arr, row + 2, col + 1, step + 1);
        Check(arr, row + 1, col + 2, step + 1);
        Check(arr, row - 1, col + 2, step + 1);
        Check(arr, row - 2, col + 1, step + 1);
        arr[row][col] = 0;
            
        }
        
  
}




int main (int argc, char *argv[]) {
    //printf("%d\n",Direction[0].vertical);
    int step = 1;
    for (int s = 0; s < N; s++)
    {
        for (int t = 0; t < N; t++) {
            Knight[s][t] = 0;
        }
    }
    
    Check(Knight, 0, 0,step);

                
    
    return 0;
}