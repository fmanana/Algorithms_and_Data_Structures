#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Length k of sub arrays
#define SUB 9
//Length of input array
#define SIZE 10

void merge(int *A, int *L, int *R, int size_L, int size_R)
{
  int key, i, j, k;

  //Insertion sort for left array
  for(i = 1; i < size_L; i++)
    {
      key = L[i];
      j = i - 1;
      while(j >= 0 && key < L[j] )
	{
	  L[j+1] = L[j];
	  j--;
	}
      L[j+1] = key;
    }
  //Insertion sort for right array
  for(i = 1; i < size_R; i++)
    {
      key = R[i];
      j = i - 1;
      while(j >= 0 && key < R[j] )
	{
	  R[j+1] = R[j];
	  j--;
	}
      R[j+1] = key;
    }

  //Merging arrays
  i = 0; j = 0; k = 0;
  while(i < size_L && j < size_R)
    {
      if(L[i] <= R[j])
	{
	  A[k] = L[i];
	  k++;
	  i++;
	}
      else
	{
	  A[k] = R[j];
	  k++;
	  j++;
	}
    }
  while(i < size_L)
    A[k++] = L[i++];
  while(j < size_R)
    A[k++] = R[j++];
}

void merge_sort(int *A, int size)
{
  int i, mid, *L, *R;
  
  if(size <= SUB)
    return;
  
  mid = size/2;
  
  L = (int *) malloc(sizeof(int) * mid);
  R = (int *) malloc(sizeof(int) * (size - mid));
  if(L == NULL || R == NULL)
    {
      printf("Error while allocating memory.\n");
      exit (1);
    }
  for(i = 0; i < mid; i++)
    {
      L[i] = A[i];
    }
  
  for(i = mid; i < size; i++)
    {
      R[i-mid] = A[i];
    }

  merge_sort(L, mid);
  merge_sort(R, size-mid);
  merge(A, L, R, mid, (size-mid));
  
  if(L != NULL)
  free(L);
  if(R != NULL)
  free(R);
}


int main()
{
  int *A;
  int i;
  
  A = (int *) malloc(sizeof(int) * SIZE);
  if(A == NULL)
    exit(1);
  
  //Allocating random numbers to the array
  srand((unsigned) time(NULL));
  /*For worst case, in order to save time changing the code
    the elements are allocated to the array as:
    A[i] = SIZE - i;
    This gives an array of decreasing numbers.*/
  for(i = 0; i < SIZE; i++)
    {
      A[i] = rand();
    }
  
  /*For best case the algorithm is run twice
    the first time to sort it and the second time
    to time it with an already sorted list.
  Best case: remove comment below for best case*/

  /*merge_sort(A, SIZE);*/

   printf("Before merge sort:\n");
  for(i = 0; i < SIZE; i++)
    {
      printf("%d\n", A[i]);
    }
  
  //Timing the algorithm
  clock_t start =  clock();
  merge_sort(A, SIZE);
  clock_t stop = clock();

  printf("\nAfter merge sort:\n");
  for(i = 0; i < SIZE; i++)
    {
      printf("%d\n", A[i]);
    }
  printf("\nMerge sort runtime: %lf", ((double)(stop-start)/CLOCKS_PER_SEC));
  printf("\n");

  free(A);
  return 0;
}
