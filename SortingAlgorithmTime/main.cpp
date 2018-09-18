#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <fstream>
using std::fixed;

using std::cout ;
using std::cin;
using std::endl;
using std::swap;
using std::string;
using std::ofstream;

/**
 * Method: heapify
 *    To heapify a subtree rooted with node.
 *
 * @param   arr[] - The pointer to number be swapped
 *          n - The pointer to number be swapped
 *          i
 *
 * @return  nothing
 */
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])         // If right child is larger than largest so far
        largest = r;
    
    
    if (largest != i)                   // If largest is not root
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);       // Recursively heapify the affected sub-tree
    }
}

/**
 * Method: heapSort
 *    Sort the array after heapifying.
 *
 * @param   arr[] - The array of numbers
 *          n - The size of array
 *
 * @return  nothing
 */
// main function to do heap sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        
        swap(arr[0], arr[i]);       // Move current root to end
        
        
        heapify(arr, i, 0);     // call max heapify on the reduced heap
    }
}

/**
 * Method: shellSort
 *    sort array using shellSort.
 *
 * @param   arr[] - The array of numbers
 *          n - The size of array
 *
 * @return  nothing
 */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];          // save a[i] in temp and make a hole at position i
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;              // put temp (the original a[i]) in its correct location
        }
    }
    return 0;
}

/**
 * Method: merge
 *    Merges two subarrays of arr[].
 *
 * @param   arr[] - Array of integers
 *          start - Starting of the array
 *          last - last element in the array
 *          size - Size of the array
 *
 * @return  nothing
 */
void merge(int arr[], int start, int last, int size)
{
    int i, j, k;
    int n1 = last - start + 1;
    int n2 =  size - last;
    //Create temp arrays
    int tempArray[n1]; // First subarray is arr[start..last]
    int tempArray2[n2]; // Second subarray is arr[last+1..size]
    
    // Copy data to temp arrays tempArray[] and tempArray2[]
    for (i = 0; i < n1; i++)
        tempArray[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        tempArray2[j] = arr[last + 1+ j];
    
    // Merge the temp arrays back into arr[start..size]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = start; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (tempArray[i] <= tempArray2[j])
        {
            arr[k] = tempArray[i];
            i++;
        }
        else
        {
            arr[k] = tempArray2[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of tempArray[], if there are any
    while (i < n1)
    {
        arr[k] = tempArray[i];
        i++;
        k++;
    }
    // Copy the remaining elements of tempArray2[], if there are any
    while (j < n2)
    {
        arr[k] = tempArray2[j];
        j++;
        k++;
    }
}

/**
 * Method: mergeSort
 *    A function to implement mergeSort.
 *
 * @param   arr[] - Array of integers
 *          start - Left index start point
 *          size - Last element right index
 *
 * @return  nothing
 */
void mergeSort(int arr[], int start, int size)
{
    if (start < size)
    {
        int m = start+(size-start)/2;
        // Sort first and second halves
        mergeSort(arr, start, m);
        mergeSort(arr, m+1, size);
        merge(arr, start, m, size);
    }
}

/**
 * Method: mergeSort
 *    A function to call the mergeSort function.
 *
 * @param   arr[] - Array of integers
 *          size - Size of the array
 *
 * @return  nothing
 */
void mergeSort(int arr[], int size)
{
    int start = 0;
    mergeSort(arr, start, size);
}
