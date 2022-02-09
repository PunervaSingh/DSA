/*
Implement a function removeEven( int *& Arr, int size ) which takes an array arr and its size and removes all the
even elements from a given array.
Input
Arr = [1,2,4,5,10,6,3]
Output
Arr = [1,5,3]
*/

#include <iostream>

using namespace std;


// O(n^2) Approach - Traverse entire array and delete even no by shifting element's from the current position to last position by one index.
int *removeEven(int *&Arr, int size) {
    for (int i = 0; i < size; i++) {
        if (Arr[i] % 2 == 0) {
            for (int j = i; j < size; j++) {
                Arr[j] = Arr[j + 1];
            }
            size--;
        }
    }
    return Arr;
}

// O(n) Approach - returning the same array but more space required as even no. stored in newly created array
int * removeEven2( int *& Arr, int size ) {
    int a[size];
    int pointer = 0;
    for(int i = 0; i < size; i++) {
        if(Arr[i] % 2 != 0) a[pointer++] = Arr[i];
    }
    int new_size = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < new_size; i++) {
        Arr[i] = a[i];
    }
    return Arr;
}

int main() {
    int *arr;
    arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    //remove_even(10, arr);
    arr = removeEven2(arr, 10);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}