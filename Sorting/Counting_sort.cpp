// Data in a particular range. It can work in almost linear time -> O(linear + Range)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void counting_sort(int a[], int n) {
    // Largest element
    int largest = -1;

    for(int i = 0; i < n; i++) {
        largest = max(largest, a[i]);
    }

    // Create a count array/vector
    vector<int> freq(largest + 1, 0);

    // Update the freq array
    for(int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Put back the elements from freq into original array.
    int j = 0; 
    for(int i = 0; i <= largest; i++) {
        while(freq[i] > 0) {
            a[j] = i;
            freq[i]--;
            j++;
        }
    }
}

int main() {
    int arr[] = {1, 4, 3, 2, 5};
    int n = sizeof(arr) / sizeof(int);

    counting_sort(arr, n);

    for(int x: arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}