// INBUILT SORT FUNCTION
// Syntax: (start of the container, end of the container, optional comparator function)
// Time Complexity: O(NlogN)

#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int arr[] = {10, 18, 91, 74, 23, 12};
    int n = sizeof(arr) / sizeof(int);

    // Not a function call, passing a function as paramenter to another function
    // Can use inbuilt comparator function greater<int>() in place of compare.
    sort(arr, arr + n, compare);
    reverse(arr, arr + n);

    // Print the output
    for(int x: arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}