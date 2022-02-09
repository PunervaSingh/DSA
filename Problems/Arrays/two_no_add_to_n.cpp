/*
Implement a function findSum(int arr[], int value, int size) which takes an array arr, a number value and size of the 
array as input and returns an array of two numbers that add up to value. In case there is more than one pair in the 
array containing numbers that add up to value, you are required to return only one such pair. If no such pair found 
then simply return the array.

Input

arr = [1,21,3,14,5,60,7,6]
value = 81
Output

arr = [21,60]
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
Method 1 - O(nlogn) time complexity. 
1. Sort the array and put two pointer(one in start and one at the end).
2. If the sum of element present at the start and at the end becomes equal to given value then return those values.
3. Else if sum is less then move start pointer one position ahead. 
4. Else the sum is greater to the value then move end pointer to one position left.
5. Otherwise return the array itself.
*/
// int *findSum(int arr[], int value, int size)
// {
//     sort(arr, arr + size);
//     int start = 0;
//     int end = size - 1;
//     static int arr_new[2];
//     while (start <= end)
//     {
//         if (arr[start] + arr[end] == value)
//         {
//             arr_new[0] = arr[start];
//             arr_new[1] = arr[end];
//             return arr_new;
//         }
//         else if (arr[start] + arr[end] < value)
//             start++;
//         else
//             end--;
//     }
//     return arr;
// }

/* 
Method 2 - Using hashmap - Time Complexity - O(n)
1. Iterate the array and store element at the given position as with complementary value.
2. Then iterate again and check if the complementary value available in map. 
3. If yes then store in array and return the array. Else return no value.
4. Print values if found or print not found if no values are found.
*/
int *findSum(int arr[], int value, int size) {
    unordered_map<int, int> mp;
    for(int i = 0; i < size; i++) {
        int temp = value - arr[i];
        mp[arr[i]] = temp;
    }
    // unordered_set<int> s;
    static int new_arr[2];
    for (int i = 0; i < size; i++) {
        int temp = value - arr[i];
        if (mp.find(temp) != mp.end()) {
            new_arr[0] = arr[i];
            new_arr[1] = temp;
        }
    }
    return new_arr;
}

int main() {
    int size = 5, value = 9;
    int arr[] = {2, 4, 5, 7, 8}; // 2 7
    // int size = 8, value = 81;
    // int arr[] = {1,21,3,14,5,60,7,6}; // 21 60
    // int size = 5, value = 80;
    // int arr[] = {1,21,3,14,5,60,7,6}; // Not Found

    if (size > 0) {
        int *arr2 = findSum(arr, value, size);
        int num1 = arr2[0];
        int num2 = arr2[1];

        if ((num1 + num2) != value)
            cout << "Not Found" << endl;
        else
            cout << num1 << " " << num2 << endl;
    } else {
        cout << "Input Array is Empty!" << endl;
    }
}