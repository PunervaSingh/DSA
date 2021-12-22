#include<iostream>
#include<climits>
using namespace std;

// Brute force approach - O(N^3)
int subarray_sum(int arr[], int n) {
    int max_sum = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if(sum > max_sum) {
                max_sum = sum;
            }
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