/*
Implement a function reArrange(int arr[], int size) which takes an array arr and its size as input and rearranges 
the elements such that all the negative elements appear on the left and positive elements appear at the right.
Consider 0 as a positive number.

Input - [10,-1,20,4,5,-9,-6]
Output - [-1,-9,-6,10,20,4,5]
*/

#include<iostream>
using namespace std;

/*
Method 1 - O(n) Time Complexity and O(n) Space complexity
*/
// void reArrange(int *arr, int size) {
//     int ans[size];
//     int pointer = 0;
//     for(int i = 0; i < size; i++) {
//         if(arr[i] < 0) {
//             ans[pointer++] = arr[i];
//         }
//     }
//     for(int j = 0; j < size; j++) {
//         if(arr[j] >= 0) {
//             ans[pointer++] = arr[j];
//         }
//     }
//     for(int k = 0; k < size; k++) {
//         arr[k] = ans[k];
//     }
// }

/*
Method 2 - O(n^2) Time Complexity and O(1) Space Complexity
*/
void reArrange(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        if (key > 0)
            continue;
        j = i - 1;
        while (j >= 0 && arr[j] > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int size = 7;
    int arr[] = {10,-1,20,4,5,-9,-6};
    reArrange(arr, size);
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}