// KADANE' ALGORITHM
// Iterate over the array and maintain two variables current_sum which maintains sum of all the elements uptil now.
// And second variable is max_sum which maintains maximum subarray sum.
// If the current_sum becomes negative then we change its value to 0 and continue adding the elements.

// ------- TIME AND SPACE COMPLEXITY ----------- //
// Time O(N) as we areiterating over the array only once.
// Space O(1) as no additional space is needed while inplementing this algorithm.

#include<iostream>
using namespace std;

int subarray_sum(int arr[], int n) {
    int current_sum = 0;
    int max_sum = 0;

    for(int i = 0; i < n; i++) {
        current_sum += arr[i];
        if(current_sum < 0) {
            current_sum = 0;
        }
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << endl << "Maximum subarray sum is: " << subarray_sum(arr, n) << endl;

    return 0;
}