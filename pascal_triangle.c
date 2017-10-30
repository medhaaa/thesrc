#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void generate(int numRows, int columnSizes[][5]);

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void generate(int numRows, int** columnSizes) {
  
    int n=1,i,j;
    for(i=0;i<numRows;i++) {
        for(j=0;j<=i;j++) {
            if(j==0 || i==j)    
                columnSizes[i][j] = 1;
            else if (i && j) 
                columnSizes[i][j] = columnSizes[i-1][j-1] + columnSizes[i-1][j];
            printf("%d ", columnSizes[i][j]);
        } 
        printf("\n");
    }
}

int main() {
   int i=0;      
   int x[5][5];
   
   memset(x, 0,sizeof(x));       
   generate(5,x);
}

/*[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
