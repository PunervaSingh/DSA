/*
Implement a function findSecondMaximum(int arr[], int size) which takes an array arr and its size as input and
returns the second maximum element in the array. If no such element found then return secondmax variable.

Assumption: Array should contain at least two unique elements.

Input

[9,2,3,6]

Output

6
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

/*
Method 1 - Time Complexity O(nlogn)
Sort the array and check from right, the first element which is not equal to the largest/Right most element 
in the array.
*/
// int findSecondMaximum(int arr[], int size) {
//     int secondmax = INT_MIN;
//     sort(arr, arr + size);
//     for (int i = size - 2; i >= 0; i--) {
//         if (arr[i] != arr[size - 1]) {
//             return arr[i];
//         }
//     }
//     return secondmax;
// }

/*
Method 2 - O(n) 
Find the largest and then find the element which is largest in the remaining elements but smaller then 
the largest element found in the first iteration.
*/
// int findSecondMaximum(int arr[], int size) {
//     int secondmax = -1;
//     int largest = arr[0];
//     for(int i = 1; i < size; i++) {
//         largest = max(largest, arr[i]);
//     }
//     for(int i = 0; i < size; i++ ) {
//         if(arr[i] != largest && (secondmax == -1 || arr[i] > secondmax)) {
//             secondmax = arr[i];
//         }
//     }
//     return secondmax;
// }

/*
Method 3 - O(n)
In one iteration, keeping checking if the current element is greater then the largest element, if it 
is then make it largest and the value stored in the largest as the second largest.
And if the element lies between largest and the second largest then make it second largest.
*/
int findSecondMaximum(int arr[], int size) {
    int largest = arr[0];
    int second_largest = -1;
    for(int i = 0; i < size; i++) {
        if(arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }
        if(arr[i] < largest && (second_largest == -1 || second_largest < arr[i])) {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int main() {
    int size = 6;
    int arr[] = {2, 3, 3, 1, 3, 3};

    int secMax = findSecondMaximum(arr, size);
    cout << secMax << endl;
    return 0;
}