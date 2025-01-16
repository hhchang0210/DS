/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <malloc.h>

#define col 5
#define row 2
#define MAX 256

int A[MAX] = {0};
int B[MAX] = {0};
int C[MAX] = {0};


void AND(int a[], int b[]){
    for(int i =0;i<MAX;i++){
        C[i] = A[i] & B[i];
        
        
    }
    
    
}

void OR(int a[], int b[]){
    
    
    for(int i =0;i<MAX;i++){
        C[i] = A[i] | B[i];
        
        
    }
    
    
}




int main()
{
   char a[] = "abcdef";
   char b[] = "cefhi";

   
   for(int i=0;i<sizeof(a)-1;i++){
       int t = (int) a[i];
       A[t] = 1;
       
   }
   
      
   for(int i=0;i<sizeof(b)-1;i++){
       int t = (int) b[i];
       B[t] = 1;
       
   }
   
   AND(A,B);
   
   for(int i=0;i<MAX;i++){
       if(C[i] != 0){
        printf("%c\n",(char) i);
       }
   }
   
   OR(A,B);
     for(int i=0;i<MAX;i++){
       if(C[i] != 0){
        printf("%c\n",(char) i);
       }
   }
    
 

    return 0;
}