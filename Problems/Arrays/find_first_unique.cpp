/*
Implement a function, findFirstUnique(int arr[], int size) which takes an array and its size as input and returns the first unique integer in the array. The function returns -1 if no unique number is found.

Input

[2,3,9,2,3,6]

Output

9
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int findFirstUnique(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size; j++) {
            if(i != j && arr[i] == arr[j]) {
                break;
            }
            if(j == size - 1 && arr[i] != arr[j]) {
                return arr[i];
            }
        }
    }
    return -1;
}

int finfFirstUnique(int arr[], int size) {
    unordered_map<int, int> mp;
    for(int i = 0; i < size; i++) {
        mp[arr[i]]++;
    }
    
    for(int i = 0; i < size; i++) {
        if(mp[arr[i]] == 1) {
            return arr[i];
        }
    }
    // ------------ OR -------------- //
    // for (auto x : mp)
    //     if (x.second == 1)
    //         cout << x.first << " ";

    return -1;
}

/*
Time Complexity - O(nlogn) because we first sort the array and then return the element which do not repeat.
If we have to find smallest unique value then this function is good to go.
*/
// int findFirstUnique(int arr[], int size) {
//     sort(arr, arr + size);
//     for(int i = 0; i < size; i++) {
//         if(arr[i] != arr[i + 1]) {
//             return arr[i];
//         } else {
//             while(arr[i] == arr[i + 1]) { 
//                 i++;
//             }
//         }
//     }
//     return -1;
// }

int main() {
    int size = 6;
    int arr[] = {2,54,7,2,6,54}; // 7
    // int size = 6;
    // int arr[] = {2,54,7,2,6,5}; // 54
    // int size = 6;
    // int arr[] = {2,2,2,1,2,1}; // -1

    int unique = findFirstUnique(arr, size);
    cout << unique << endl;
    return 0;
}