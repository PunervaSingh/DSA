// KEY IDEA - Insertion sort is similar to playing cards in our hands. 
// Insert the card in its correct position in a sorted part.

#include<iostream>
using namespace std;

// Time O(N^2)
// Space O(1)
// Sort the elements in increasing order
void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int current = arr[i];
        int prev = i - 1;

        // loop to find the right index where the current element should be inserted.
        while((prev >=  0) && (arr[prev] > current)) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }
}

int main() {
    int arr[] = {3, 2, 4, 5, 1};
    int n = sizeof(arr) / sizeof(int);

    insertion_sort(arr, n);

    for(int x: arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}