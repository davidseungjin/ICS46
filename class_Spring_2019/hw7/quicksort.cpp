/* C implementation QuickSort */
#include<iostream>
#include<string>

using namespace std;

// A utility function to swap two elements
void swap(string* a, string* b)
{
    string t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
int partition (string arr[], int low, int high)
{
    string pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low --> Starting index,
 high --> Ending index */
void quickSort(string arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(string arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        std::cout << arr[i] << std::endl;
}

// Driver program to test above functions
int main()
{
    string arr[] = {"david", "caleb", "abigail", "solomon", "abraham", "aaron", "Aaron"};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    std::cout << "Sorted array is : \n";
    printArray(arr, n);
    return 0;
}
