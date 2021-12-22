// ------------ BINARY SEARCH -------------- //
// Efficient searching algorithm to find the index of element in a given sorted array.
// It is fast and search space is monotonic(non-decreasing or non-increasing).

// ------- TIME AND SPACE COMPLEXITY ----------- //
// Time O(log N) as we are decreasing the length of array to half of the current length.
// Space O(1) as no additional space is needed while inplementing this algorithm.

#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;

    // Until the start become greater then the end this loop will keep on executing.
    while(start <= end) {
        // Getting the middle index of the array
        int mid = (start + end) / 2;

        // If the middle element of the element is equal to the key then we will return mid.
        if(arr[mid] == key) {
            return mid;
        } 
        else if(arr[mid] > key) { 
            // If the middle element is greater than the key then it means the key lies in the first half.
            // So we bring end to the position before mid.
            end = mid - 1;
        } 
        else {
            // If the middle element is smaller than the key then the key lies in second half of the array.
            // So we bring the start to the position after the mid.
            start = mid + 1;
        }
    }

    return -1;
}


int main() {
    int arr[] = {10, 14, 20, 32, 50};
    int n = sizeof(arr) / sizeof(int);

    int key;
    cout << "Enter element to be searched: ";
    cin >> key;

    int index = binary_search(arr, n, key);
    if(index != -1) {
        cout << key << " was found at the index: " << index;
    } else {
        cout << key << " is not present in the array";
    }
    cout << endl;

    return 0;
}