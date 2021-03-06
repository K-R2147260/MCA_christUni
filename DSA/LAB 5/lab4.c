//LAB 4 PROGRAM

#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *, int);
void insertion_sort(int *, int);
void quick_sort(int *, int, int);
void print_array(int *, int);
void swap(int *, int *);
int partition(int *, int, int);

int quickshift = 0, quickcomp = 0;

int main()
{
    int size, choice;
    int *array1, *array2, *array3, *array4;
    int i, c = 1, cho, tno;
    do
    {

        printf("Enter the size of the array: ");
        scanf("%d", &size);
        c = 1;
        if (size < 0)
        {
            c = 0;
        }
    } while (c == 0);
    array1 = (int *)malloc(size * sizeof(int));
    array2 = (int *)malloc(size * sizeof(int));
    array3 = (int *)malloc(size * sizeof(int));
    array4 = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        tno = rand() % size;
        array1[i] = tno;
        array2[i] = tno;
        array3[i] = tno;
        array4[i] = tno;
    }

    do
    {
        cho = 1;
        printf("Enter the choice:\n1. Selection sort\n2. Insertion sort\n3. Quick sort\n4. Exit ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            selection_sort(array2, size);
            print_array(array2, size);
            break;
        case 2:
            selection_sort(array2, size);
            print_array(array2, size);
            break;
        case 3:
            insertion_sort(array3, size);
            print_array(array3, size);
            break;
        case 4:
            quick_sort(array4, 0, size - 1);
            print_array(array4, size);
            printf("Quick sort: %d comparisons, %d shifts\n", quickcomp, quickshift);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        printf("\nDo you want to continue? 0 to continue any key to exit: ");
        scanf("%d", &cho);
    } while (cho == 0);
    free(array1);
    free(array2);
    free(array3);
    free(array4);
    return 0;
}



void selection_sort(int *array, int size)
{
    int i, j, min_index;
    int comparisons = 0;
    int shifts = 0;
    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            comparisons++;
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(&array[i], &array[min_index]);
            shifts++;
        }
    }
    printf("Selection sort: %d comparisons, %d shifts\n", comparisons, shifts);
}

void insertion_sort(int *array, int size)
{
    int i, j, temp;
    int comparisons = 0;
    int shifts = 0;
    for (i = 1; i < size; i++)
    {
        j = i;
        comparisons++;
        while ((j > 0) && (array[j - 1] > array[j]))
        {
            if (array[j - 1] > array[j])
            {
                comparisons++;
            }
            temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j--;

            shifts++;
        }
    }
    printf("Insertion sort: %d comparisons, %d shifts\n", comparisons, shifts);
}

int partition(int array[], int low, int high)
{

    int pivot = array[high];
    int i = (low - 1);
    int j;

    for (j = low; j < high; j++)
    {
        quickcomp++;
        if (array[j] <= pivot)
        {

            i++;

            swap(&array[i], &array[j]);
            quickshift++;
        }
    }

    swap(&array[i + 1], &array[high]);
    quickshift++;

    return (i + 1);
}

void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {

        int p = partition(array, low, high);

        quick_sort(array, low, p - 1);

        quick_sort(array, p + 1, high);
    }
}

void print_array(int *array, int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("\t%d ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



