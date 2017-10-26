#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define ROWS 5
#define COLS 5

int isValidNode(int m[][COLS], int row, int col, bool visited[][COLS]){
    return  (row < ROWS) && (row >= 0) && 
            (col < COLS) && (col >= 0) &&
             m[row][col] && !visited[row][col];
} 

void DFS(int m[][COLS], int row, int col, bool visited[][COLS]){
    static int rowPos[]={ 0, -1, -1, -1, 0, 1, 1, 1};
    static int colPos[]={-1,  0, -1,  1, 1, 1, 0, -1};
    int i;
    
    printf("Visited row=%d col=%d\n",row,col);
    visited[row][col] = true;
    
    for(i=0;i<8;i++) {
        if(isValidNode(m,row+rowPos[i],col+colPos[i],visited)) {
           printf("isValidNode:do DFS row=%d col=%d\n", row, col);    
           DFS(m,row+rowPos[i],col+colPos[i],visited);
        }
    }
}

int countIslands(int m[][COLS]) {
    int count=0, i,j;
    bool visited[ROWS][COLS];
    memset(visited, 0, sizeof(visited));
    for(i = 0; i < ROWS; i++) {
        for(j = 0;j < COLS; j++) {
            if(m[i][j] && !visited[i][j]) {
                printf("DFS called from CountIslands i=%d j=%d\n", i, j);
                DFS(m,i,j,visited);
                count++;
            }
        }
    }
    return count;
}

int main() {
   int m[][COLS] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}}; 
   int num=0;    
   num = countIslands(m);
   printf("Number of Islands = %d\n", num);
}
