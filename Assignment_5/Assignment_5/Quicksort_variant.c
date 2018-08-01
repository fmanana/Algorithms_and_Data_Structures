#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

//  Swap function to exchange elements
void swap(int *a, int *b)
{
    int helper = *a;
    *a = *b;
    *b = helper;

}
/*  First partition function paritions the array into subarrays
    around the first pivot
*/
int Partition1(int *array, int p, int r)
{
    int piv_1, i;
    piv_1 = array[p];
    i = p;
    
    for(int j = p + 1; j <= r; j++)
    {
        if(array[j] <= piv_1)
        {
            i += 1;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[p], &array[i]);

    return i;
}

/*  Second partition function partitions the array around the
    second pivot point
*/
int Partition2(int *array, int p, int r)
{
    int piv_2, k;
    piv_2 = array[p+1];
    k = p + 1;
    for(int j = p + 2; j <= r; j++)
    {
         if(array[j] <= piv_2)
        {
            k += 1;
            swap(&array[k], &array[j]);
        }
    }
    swap(&array[p+1], &array[k]);

    return k;
}

void Quicksort(int *array, int p, int r)
{
    int first, second;
    if(p < r)
    {
        first = Partition1(array, p, r);
        second = Partition2(array, p, r);
        Quicksort(array, p, (first - 1));
        Quicksort(array, (first + 1), second - 1);
        Quicksort(array, second + 1, r);
    }
}
int main()
{
    int i;
    int array[SIZE];
    srand((unsigned) time(0));
    for(i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 50 + 1;
    }

    Quicksort(array, 0, SIZE - 1);

    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}