#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &array, int s, int e) {
    int i = s;
    int m = (s+e) / 2;
    int j = m + 1;

    vector<int> temp;

    while(i <= m &&  j <= e) {
        if(array[i] < array[j]) {
            temp.push_back(array[i]);
            i++;
        }
        else{
            temp.push_back(array[j]);
            j++;
        }
    }

    // Copy remaining elements from first array
    while(i <= m) {
        temp.push_back(array[i]);
        i++;
    }

    // Or copy the remaining elements from second array
    while(j <= e) {
        temp.push_back(array[j]);
        j++;
    }

    // Copy bak the element from temp to original array
    int idx = 0;
    for(int k = s; k <= e; k++) {
        array[k] = temp[idx++];
    }
}

// Sorting method
void mergesort(vector<int> &arr, int s, int e) {
    // Base case
    if(s >= e) {
        return;
    }

    // Recursion case
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    return merge(arr, s, e);
}

int main() {
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(7);
    arr.push_back(6);
    arr.push_back(4);

    int s = 0;
    int e = arr.size() - 1;
    mergesort(arr, s, e);
    for(int x: arr) {
        cout << x << ",";
    }
    cout << endl;

    return 0;
}