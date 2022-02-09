/*
Implement a function findMinimum(int arr[], int size) which takes an array arr and its size and returns the
smallest number in the given array.

Input

arr = [9,2,3,6]
Output
2
*/

#include <iostream>
#include <algorithm>
using namespace std;

/*
Method 1 - Iterative approach - 
Traverse through the array and compare element present at the index with the min element stored in the variable.
If the element is smaller then the last stored value in the minimum variable then replace the value with 
the current value. Return the smallest value found in the array.
*/
// int findMinimum(int arr[], int size) {
//     int minimum = arr[0];
//     for (int i = 1; i < size; i++)
//         if (arr[i] < minimum)
//             minimum = arr[i];
//     return minimum;
// }


/*
Method 2 - Recursive approach
*/
// int findMinimum(int arr[], int size) {
//     return (size == 1) ? arr[0] : min(arr[0], findMinimum(arr + 1, size - 1));
// }


/*
Method 3 - By using the built in function for finding the minimum value in the array.
*/
int findMinimum(int arr[], int size) {
    return *min_element(arr, arr + size);
}

int main()
{
    int size = 4;
    int arr[] = {9, 2, 3, 6};

    int min = findMinimum(arr, size);
    cout << min << endl;
    return 0;
}