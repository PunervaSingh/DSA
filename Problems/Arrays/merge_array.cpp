/*
Implement a function mergeArrays(int arr1[], int arr2[], int arr1Size,int arr2Size) which merges two sorted arrays 
into another sorted array. Definition of the function is given.

Input
arr1 = [1,3,4,5]
arr2 = [2,6,7,8]
Output
arr = [1,2,3,4,5,6,7,8]
*/

#include <iostream>
using namespace std;

/*
Method 1 (O(n1 * n2) Time and O(n1+n2) Extra Space)

1. Create an array arr3[] of size n1 + n2.
2. Copy all n1 elements of arr1[] to arr3[]
3. Traverse arr2[] and one by one insert elements (like insertion sort) of arr3[] to arr1[]. 
This step take O(n1 * n2) time.
*/

// Best Approach - Time complexity(O(n+m)) where n is size of first array and m is the size of the second array.
// Extra space(O(n+m)) needed for merging both array into one.
int *mergeArrays(int arr1[], int arr2[], int n1, int n2) {
    int *arr3 = new int[n1 + n2];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1)
        arr3[k++] = arr1[i++];
    while (j < n2)
        arr3[k++] = arr2[j++];
    return arr3;
}

int main() {
    int size1 = 5, size2 = 3;
    int arr[] = {1, 12, 14, 17, 23};
    int arr1[] = {11, 19, 27};
    int *arr2 = mergeArrays(arr, arr1, size1, size2);
    for (int i = 0; i < size1 + size2; i++) {
        cout << arr2[i] << " ";
    }
    delete arr2;
    return 0;
}