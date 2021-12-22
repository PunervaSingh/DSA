// KEY IDEA - Take larger element to the end by repeatedly swapping the adjacent elements.
// Just like what happens to the bubbles when we boil the water. Bigger bubbles comes to the top of water.
#include<iostream>
using namespace std;

// Time O(N^2)
// Space O(1)
// Sort the elements in increasing order
void bubble_sort(int a[], int n){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n - i - 2; j++){
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main() {

    int arr[] = {-2, 5, 3, -5, 4, 9, -11};
    int n = sizeof(arr) / sizeof(int);

    bubble_sort(arr, n);

    for(int x: arr) {
        cout << x << " ";
    }

    return 0;
}