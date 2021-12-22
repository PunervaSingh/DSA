// SELECTION SORT
// Repeatedly find the minimum element from the unsorted part and put it at the beginning.

#include<iostream>
using namespace std;

// Time O(N^2)
// Space O(1)
// Sort the elements in increasing order
void selection_sort(int arr[], int n) {
    for(int pos = 0; pos < n - 1; pos++) {
        int current = arr[pos];
        int min_pos = pos;

        // find the minimum element from the remaining array
        for(int j = pos; j < n; j++) {
            if(arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }
        // swap outside the loop
        swap(arr[min_pos], arr[pos]);
    }
}

int main() {
    int arr[] = {1, 4, 3, 2, 5};
    int n = sizeof(arr) / sizeof(int);

    selection_sort(arr, n);

    for(int x: arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}