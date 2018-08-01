//Author: Fezile Manana

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define size of the array
#define SIZE 10

//Function to swap elements
void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main()
{
  int *arr;
  int i, j;
  int min;

  //Initialising random no. generator
  srand((unsigned) time(NULL));

  arr = (int *) malloc(sizeof(int) * SIZE);
  //Generating random elements
  for(i = 0; i < SIZE; i++)
    {
      //Random no. generator uses system time
      arr[i] = rand();
    }
  printf("Before selection sort:\n");
  for(i = 0; i < SIZE; i++)
    {
      printf("%d\n", arr[i]);
    }
  printf("\nAfter selection sort:\n");

  //Algorithms begins here. Timing starts.
  clock_t start = clock();
  for(i = 0; i < SIZE; i++)
    {
      min = i;
      //Running from end of array towards current position
      for(j = i; j < SIZE; j++)
        {
            /*Setting the current position to the minimum
            then always replacing min with a smaller element*/
            if(arr[j] < arr[min])
                min = j;
        }
        //Function call to swap current with min
        swap(&arr[i], &arr[min]);
    }
  //End of algorithm. Timing ends.
  clock_t end = clock();

  for(i = 0; i < SIZE; i++)
    {
      printf("%d\n", arr[i]);
    }
  printf("Run time: %lfs\n", (double)(end - start) / CLOCKS_PER_SEC);
  free(arr);
  return 0;
}
