#include <iostream>
using namespace std;

// Function to merge two sorted halves
void merge(int arr[], int low, int mid, int high)
{
    int temp[100]; // Temporary array
    int left = low;
    int right = mid + 1;
    int index = low;

    // Compare elements from both halves
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            left++;
        }
        else
        {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    // Copy remaining elements from left half
    while (left <= mid)
    {
        temp[index] = arr[left];
        left++;
        index++;
    }

    // Copy remaining elements from right half
    while (right <= high)
    {
        temp[index] = arr[right];
        right++;
        index++;
    }

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both halves
    merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {5, 2, 8, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}