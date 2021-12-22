// Searching algorithm to find the index of element in a given array.
// If element is found then return the index else return -1.

// ------- TIME AND SPACE COMPLEXITY ----------- //
// Time O(N) as we are iterating whole array from initial element to the end.
// Space O(1) as no additional space is needed while inplementing this algorithm.

#include<iostream>
using namespace std;

int linear_search(int arr[], int n, int key) {

    // Iterating over the whole array from starting element to the last one by one.
    // If the present element is equal to the key that we are searching for then we return the index.
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }

    // If we come out of the for loop then it is evident that the key was not found in the array so we return -1.
    return -1;
}

int main() {
    int arr[] = {10, 14, 20, 32, 50};
    int n = sizeof(arr) / sizeof(int);

    int key;
    cout << "Enter element to be searched: ";
    cin >> key;

    int index = linear_search(arr, n, key);
    if(index != -1) {
        cout << key << " was found at the index: " << index;
    } else {
        cout << key << " is not present in the array";
    }
    cout << endl;

    return 0;
}