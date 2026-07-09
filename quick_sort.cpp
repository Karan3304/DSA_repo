#include <iostream>
#include <vector>
using namespace std;

// Partition function
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];   // First element as pivot
    int i = low;
    int j = high;

    while (i < j)
    {
        // Move i until an element greater than pivot is found
        while (arr[i] <= pivot && i < high)
            i++;

        // Move j until an element smaller than or equal to pivot is found
        while (arr[j] > pivot && j > low)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    // Place pivot in its correct position
    swap(arr[low], arr[j]);

    return j;
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}