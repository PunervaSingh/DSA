#include<iostream>
using namespace std;


// Time O(N)
void reverse_array(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {12, 22, 44, 54, 88};
    int n = sizeof(arr) / sizeof(int);

    // Print array before reversing
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverse_array(arr, n);

    // Print array after reversing
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}