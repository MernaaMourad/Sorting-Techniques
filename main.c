#include <stdio.h>
#include <stdlib.h>




void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}




void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        } // put min at the correct position
        swap(&array[min_idx], &array[step]);
    }
}






void insertionSort(int arr[], int n)

{

    int i, j,key;

    for (i = 1; i < n; i++)
    {
        key=arr[i];
        j=i-1;
        /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

}



void bubbleSort(int arr[], int n)

{

    int i,j;
    for(i=0; i<n-1; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}


void merge(int arr[], int l, int m, int r)

{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;/* create temp arrays */
    int L[n1],R[n2];/* Copy data to temp arrays L[] and R[] */
    for(i=0; i<n1; i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0; j<n2; j++)
    {
        R[j]=arr[m+1+j];
    }/* Merge the temp arrays back into arr[l..r]*/
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)

{

    if (l < r) {

        // Same as (l+r)/2, but avoids overflow for

        // large l and h

        int m = l + (r - l) / 2;



        // Sort first and second halves

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);



        merge(arr, l, m, r);

    }

}



int partition(int arr[],int first,int last)
{
    int lasts1=first;
    int firstUnknown=first+1;
    while(firstUnknown<=last)
    {
        if(arr[firstUnknown]<arr[first])
        {
            lasts1=lasts1+1;
            swap(&arr[firstUnknown], &arr[lasts1]);
        }
        firstUnknown=firstUnknown+1;
    }
    swap(&arr[first], &arr[lasts1]);
    return lasts1;
}

void quicksort(int arr[],int first,int last)
{
    int q;

    if(first<last)
    {
        q=partition(arr,first,last);
        quicksort( arr, first, q-1);
        quicksort( arr, q+1, last);
    }
}


void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// driver code
int main()
{
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    printf("Sorted array in Acsending selection Order:\n");
    printArray(data, size);
    int data1[] = {20, 12, 10, 15, 2};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    insertionSort(data1, size1);
    printf("Sorted array in Acsending insertion Order:\n");
    printArray(data1, size1);
    int data2[] = {20, 12, 10, 15, 2};
    int size2 = sizeof(data2) / sizeof(data2[0]);
    bubbleSort(data2, size2);
    printf("Sorted array in Acsending bubblesort Order:\n");
    printArray(data2, size2);
    int data3[] = {20, 12, 10, 15, 2};
    int size3 = sizeof(data3) / sizeof(data3[0]);

    int z=0;

    int y=size3-1;
    mergeSort(data3,z,y);
    printf("Sorted array in Acsending mergesort Order:\n");
    printArray(data3, size3);
    int data4[] = {20, 12, 10, 15, 2};
    int size4 = sizeof(data4) / sizeof(data4[0]);
    quicksort(data4,0,size4-1);
    printf("Sorted array in Acsending quicksort Order:\n");
    printArray(data4, size4);





    return 0;
}








