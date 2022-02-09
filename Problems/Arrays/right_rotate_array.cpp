/*
Implement a function rightRotate(int arr[], int size) which takes an array arr and rotate it right by k times.
This means that the right-most elements will appear at the left-most position in the array.

Input
arr = [1,2,3,4,5]
k = 1
Output
arr = [5,1,2,3,4]
*/

#include <iostream>
using namespace std;

/*
Method 1 - O(n) Time Complexity and O(k) space complexity
*/
// int * rotateArray(int arr[], int size, int k) {
//     int temp[k];
//     int start = 0;
//     for (int i = size - k; i < size; i++) {
//         temp[start++] = arr[i];
//     }
//     for (int i = size - k - 1; i >= 0; i--) {
//         arr[i + k] = arr[i];
//     }
//     for(int i = 0; i < size - k; i++) {
//         arr[i] = temp[i];
//     }
//     return arr;
// }

/*
Method 2 - O(n) Time complexity and O(1) space complexity
*/
void rotate_arr(int i, int j, int *arr) {
    int start = i;
    int end = j - 1;
    while(start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
    }
}
int * rotateArray(int arr[], int size, int k) {
    rotate_arr(0, size - k, arr);
    rotate_arr(size - k, size, arr);
    rotate_arr(0, size, arr);
    return arr;
}

int main() {
    int size = 6;
    int arr[] = {3, 6, 1, 8, 4, 2};
    int k = 4;

    int * new_arr = rotateArray(arr, size, k);

    for (int i = 0; i < size; i++) {
        cout << new_arr[i] << " ";
    }
    cout << endl;
    return 0;
}