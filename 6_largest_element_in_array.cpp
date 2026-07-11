#include <iostream>
using namespace std;

int largestElement(int arr[], int n) {
    int largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    int arr[] = {12, 45, 7, 89, 34, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Largest Element = " << largestElement(arr, n);

    return 0;
}