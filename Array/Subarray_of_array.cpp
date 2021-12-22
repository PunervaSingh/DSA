// Subarray - A smaller continuous part of an array
// If there are N number of elements in the array then the number of subarray is directly proportional to N^2.

// ------- TIME AND SPACE COMPLEXITY ----------- //
// Time O(N^3) as we are using three nested loops to get the subarrays.
// Space O(1) as no additional space is needed while inplementing this algorithm.

#include<iostream>
using namespace std;

void print_subarray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = i; k <= j; k++) {
                cout << arr[k] << ",";
            }
            cout << endl;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    print_subarray(arr, n);

    return 0;
}