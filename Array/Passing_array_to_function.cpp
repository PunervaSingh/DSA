#include<iostream>
using namespace std;

void print_array(int *arr, int n) {
    cout << "Size of the array in the print function: " << sizeof(arr) << endl;

    // Updating value of first element of the array in function
    cout << "Updating value of the firt element to -1" << endl;
    arr[0] = -1; 
    // as we are passing pointer to the array then all the changes made in this function,
    // will take place on the array in the main funtion. 
    // It is the same array or we can say they have common memory.

    cout << "ARRAY: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    print_array(arr, n);

    cout << "Size of array in main: " << sizeof(arr) << endl;
    cout << "ARRAY: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}