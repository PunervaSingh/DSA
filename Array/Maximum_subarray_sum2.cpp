// PREFIX SUM APPROACH
// Maintain cumulative sum of the elements from the start to the current index in an array prefix.
// Sum of a subarray will be cumulative sum of last element of subarray minus the cumulative sum of the element before first element of subarray.


// ------- TIME AND SPACE COMPLEXITY ----------- //
// Time O(N^2) as we are having two nested loops.
// Space O(N) as we are creating an additional array to store cumulative sum uptil that index.

#include<iostream>
using namespace std;

int subarray_sum(int arr[], int n) {
    int prefix[100] = {0};
    prefix[0] = arr[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int max_sum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int subarraySum = i > 0? prefix[j] - prefix[i - 1] : prefix[j];

            max_sum = max(max_sum, subarraySum);
        }
    }
    return max_sum;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << endl << "Maximum subarray sum is: " << subarray_sum(arr, n) << endl;

    return 0;
}