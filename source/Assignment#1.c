// Leandro Ebner 2024
// Assignment #1: Multiplication-Table

#include <stdio.h>

int rows, collumns, i, j;

int main(){
  
  printf("Insert amount of row(s):\n");
  scanf("%d", &rows);
  printf("Received %d row(s).\nInsert amount of collumn(s):\n", rows);
  scanf("%d", &collumns);
  printf("Received %d collumn(s).\n\n", collumns);

  int array[rows];
  
  for(i=0; i < rows; i++){
    array[i] = i+1;
    }
  
  for(j=0; j < collumns; j++){
    for(i=0; i < rows; i++){printf("%d  ", array[i]*(j+1));}
    printf("\n");
    }
}
