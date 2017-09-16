#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 5

int compare(const void *arg1, const void *arg2) {
  return  (*(int *)arg1 - *(int *)arg2);
}

int main() {
  int i = 0;
  int arr[ARR_SIZE] = {2, 3, 1 ,3 ,5};
  
  for(i = 0; i != ARR_SIZE; ++i) 
    printf("%d ", arr[i]);
  
  printf("\n");
  
  qsort((void *)arr, ARR_SIZE, sizeof(int), compare);
  
  for(i = 0; i != ARR_SIZE; ++i)
    printf("%d ", arr[i]);  
}
