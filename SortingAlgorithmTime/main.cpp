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


/**
 * Method: swap
 *    A utility function to swap two elements.
 *
 * @param   int*a - Element that needs to be swaped with second
 *          int*b - Element thats going to be swaped with first
 *
 * @return  nothing
 */
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * Method: bubbleSort
 *     This function takes last element as pivot, places
 *     the pivot element at its correct position in sorted
 *     array, and places all smaller (smaller than pivot)
 *     to left of pivot and all greater elements to right
 *     of pivot
 *
 * @param   arr[] - Array of integers
 *          low - left side index
 *          high - right side index
 *
 * @return  nothing
 */
/*  */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


/**
 * Method: quickSort
 *    The function that implements QuickSort
 *
 * @param    arr[] - Array to be sorted
 *           low  - Starting index
 *           high  - Ending index
 *
 * @return  nothing
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //index is partitioning index, arr[low] is now at right place
        int index = partition(arr, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

/**
 * Method: quickSort
 *    A function to call the quickSort function.
 *
 * @param   arr[] - Array of integers
 *          size - Size of the array
 *
 * @return  nothing
 */
void quickSort(int arr[],int size)
{
    int start = 0;
    quickSort(arr, start, size);
}


/**
 * Method: Swap
 *    Function to sort an array using selection sort.
 *
 * @param   arr[] - The number to be swapped
 *          size - Size of the array
 *
 * @return  nothing
 */
void selectionSort(int arr[], int size)
{
    int i, j, min;
    for (i = 0; i < size-1; i++)            // One by one move boundary of unsorted subarray
    {
        min = i;                            // Find the minimum element in unsorted array
        for (j = i+1; j < size; j++){
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);           // Swap the found minimum element with the first element
    }
}

/**
 * Method: insertionSort
 *    Function to sort an array using insertion sort.
 *
 * @param   arr[] - Array of integers
 *          size - Size of the array
 *
 * @return  nothing
 */
void insertionSort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)      //Elements that are greater than key
        {
            arr[j+1] = arr[j];              //Move elements to one position ahead of their current position
            j = j-1;
        }
        arr[j+1] = key;
    }
}


/**
 * Method: bubbleSort
 *    A function to implement bubble sort.
 *
 * @param   arr[] - Array of integers
 *          size - Size of the array
 *
 * @return  nothing
 */
void bubbleSort(int arr[], int size)
{
    
    int i, j;
    for (i = 0; i < size-1; i++){
        for (j = 0; j < size-i-1; j++){      // Last i elements are already in place
            if (arr[j] > arr[j+1]){
                
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


// Driver program
int main()
{
    
    std::chrono::high_resolution_clock::time_point  begin, end;
    std::chrono::duration<double>                   elapsed_time;
    double                                          elapsed_seconds;
    int arrAccending[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
    int accending = sizeof(arrAccending)/sizeof(arrAccending[0]);
    int arrDecending[] = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int decending = sizeof(arrDecending)/sizeof(arrDecending[0]);
    int randomArray[] = {12,66,84,30,34,92,99,38,40,69,95,88,47,17,48,71,3,67,5,70,18,72,46,82,59,63,41,35,42,21,1,60,20,94,76,91,53,33,90,81,73,56,4,45,96,32,74,61,24,68,14,75,93,79,97,15,62,98,22,85,10,27,51,54,39,77,25,9,26,55,87,28,31,19,37,86,44,23,7,83,13,11,43,50,36,64,2,6,78,57,80,58,8,52,16,49,29,65,89,100};
    int random = sizeof(randomArray)/sizeof(randomArray[0]);
    
    
    //HeapSort
    
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapAccending = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapDecending = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapRandom = elapsed_seconds;
    
    //HeapSort 2
    
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapAccending2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapDecending2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapRandom2 = elapsed_seconds;
    cout << endl;
    
    
    //HeapSort
    
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapAccending3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapDecending3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();                  // record start time
    heapSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeHeapRandom3 = elapsed_seconds;
    cout << endl;
    
    // ========================
    
    //ShellSort
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellAccen = elapsed_seconds;
    
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellDecend = elapsed_seconds;
    
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellRandom = elapsed_seconds;
    cout << endl;
    
    //ShellSort
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellAccen2 = elapsed_seconds;
    
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellDecend2 = elapsed_seconds;
    
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellRandom2 = elapsed_seconds;
    cout << endl;
    
    //ShellSort
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellAccen3 = elapsed_seconds;
    
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellDecend3 = elapsed_seconds;
    
    
    
    begin = std::chrono::high_resolution_clock::now();
    shellSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeShellRandom3 = elapsed_seconds;
    cout << endl;
    
    //======================
    
    
    
    //MergeSort
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(arrAccending, accending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeAccend = elapsed_seconds;
    cout << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(arrDecending, decending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeDecend = elapsed_seconds;
    cout << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(randomArray, random-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeRandom = elapsed_seconds;
    cout << endl;
    
    //MergeSort
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(arrAccending, accending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeAccend2 = elapsed_seconds;
    cout << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(arrDecending, decending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeDecend2 = elapsed_seconds;
    cout << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(randomArray, random-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeRandom2 = elapsed_seconds;
    cout << endl;
    
    //MergeSort
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(arrAccending, accending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeAccend3 = elapsed_seconds;
    cout << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(arrDecending, decending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeDecend3 = elapsed_seconds;
    cout << endl;
    
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(randomArray, random-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeMergeRandom3 = elapsed_seconds;
    cout << endl;
    
    //======================
    //Quick Sort 1
    begin = std::chrono::high_resolution_clock::now();
    quickSort(arrAccending, accending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickAccend = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    quickSort(arrDecending, decending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickDecend = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    quickSort(randomArray, random-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickRandom = elapsed_seconds;
    //Quick Sort 2
    begin = std::chrono::high_resolution_clock::now();
    quickSort(arrAccending, accending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickAccend2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    quickSort(arrDecending, decending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickDecend2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    quickSort(randomArray, random-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickRandom2 = elapsed_seconds;
    //Quick Sort 3
    begin = std::chrono::high_resolution_clock::now();
    quickSort(arrAccending, accending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickAccend3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    quickSort(arrDecending, decending-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickDecend3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    quickSort(randomArray, random-1);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeQuickRandom3 = elapsed_seconds;
    //======================
    // Selection Sort 1
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionAccend = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionDecend = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionRandom = elapsed_seconds;
    // Selection Sort 2
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionAccend2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionDecend2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionRandom2 = elapsed_seconds;
    // Selection Sort 3
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionAccend3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionDecend3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeSelectionRandom3 = elapsed_seconds;
    //=================
    // Bubble Sort 1
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleAccend = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleDecend = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleRandom = elapsed_seconds;
    // Bubble Sort 2
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleAccend2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleDecend2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleRandom2 = elapsed_seconds;
    // Bubble Sort 3
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleAccend3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleDecend3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    bubbleSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeBubbleRandom3 = elapsed_seconds;
    //=====================
    //Inseriton Sort 1
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionAccend = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionDecend = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionRandom = elapsed_seconds;
    
    
    //Inseriton Sort 1
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionAccend2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionDecend2 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionRandom2 = elapsed_seconds;
    //Inseriton Sort 1
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(arrAccending, accending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionAccend3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(arrDecending, decending);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionDecend3 = elapsed_seconds;
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(randomArray, random);
    end   = std::chrono::high_resolution_clock::now();
    elapsed_time    = end - begin;                                      // get the period of time elapsed
    elapsed_seconds = elapsed_time.count();                             // convert to (fractional)// record end time
    double timeInsertionRandom3 = elapsed_seconds;
    //================
    
    
    double avgHeapAccend = (timeHeapAccending + timeHeapAccending2+timeHeapAccending3)/3;
    double avgHeapDecend = (timeHeapDecending+timeHeapDecending2+timeHeapDecending3)/3;
    double avgHeapRandom = (timeHeapRandom+timeHeapRandom2+timeHeapRandom3)/3;
    double avgShellAccend = (timeShellAccen+timeShellAccen2+timeShellAccen3)/3;
    double avgShellDecend = (timeShellDecend+timeShellDecend2+timeShellDecend3)/3;
    double avgShellRandom = (timeShellRandom+timeShellRandom2+timeShellRandom3)/3;
    double avgMergeAccend = (timeMergeAccend+timeMergeAccend2+timeMergeAccend3)/3;
    double avgMergeRandom = (timeMergeRandom+timeMergeRandom3+timeMergeRandom2)/3;
    double avgMergeDecend = (timeMergeDecend+timeMergeDecend2+timeMergeDecend3)/3;
    double avgQuickAccend = (timeQuickAccend+timeQuickAccend2+timeQuickAccend3)/3;
    double avgQuickDecend = (timeQuickDecend+timeQuickDecend2+timeQuickDecend3)/3;
    double avgQuickRandom = (timeQuickRandom+timeQuickRandom2+timeQuickRandom3)/3;
    double avgSelectionAccend = (timeSelectionAccend+timeSelectionAccend2+timeSelectionAccend3)/3;
    double avgSelectionDecend = (timeSelectionDecend+timeSelectionDecend2+timeSelectionDecend3)/3;
    double avgSelectionRandom = (timeSelectionRandom+timeSelectionRandom2+timeSelectionRandom3)/3;
    double avgBubbleAccend = (timeBubbleAccend+timeBubbleAccend2+timeBubbleAccend3)/3;
    double avgBubbleDecend = (timeBubbleDecend+timeBubbleDecend2+timeBubbleDecend3)/3;
    double avgBubbleRandom = (timeBubbleRandom+timeBubbleRandom2+timeBubbleRandom3)/3;
    double avgInsertionAccend = (timeInsertionAccend+timeInsertionAccend2+timeInsertionAccend3)/3;
    double avgInsertionDecend = (timeInsertionDecend+timeInsertionDecend2+timeInsertionDecend3)/3;
    double avgInsertionRandom = (timeInsertionRandom+timeInsertionRandom2+timeInsertionRandom3)/3;
    ofstream myfile;
    myfile.open ("sortingResults.csv");
    myfile << "Selection,"<< avgSelectionAccend << "," << avgSelectionDecend << "," << avgSelectionRandom << "\n";
    myfile << "Insertion,"<< avgInsertionAccend << "," << avgInsertionDecend << "," << avgInsertionRandom << "\n";
    myfile << "Bubble,"<< avgBubbleAccend << "," << avgBubbleDecend << "," << avgBubbleRandom << "\n";
    myfile << "Quick,"<< avgQuickAccend << "," << avgQuickDecend << "," << avgQuickRandom << "\n";
    myfile << "Heap,"<< avgHeapAccend << "," << avgHeapDecend << "," << avgHeapRandom << "\n";
    myfile << "Merge,"<< avgMergeAccend << "," << avgMergeDecend << "," << avgMergeRandom << "\n";
    myfile << "Shell,"<< avgShellAccend << "," << avgShellDecend << "," << avgShellRandom << "\n";
    myfile.close();
}
