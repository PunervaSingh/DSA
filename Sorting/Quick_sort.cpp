#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &a, int s, int e) {
    int pivot = a[e];
    int i = s - 1;

    for(int j = s; j < e; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[e], a[i+1]);
    return i + 1;
}

void quick_sort(vector<int> &a, int s, int e) {
    // Base Case
    if(s >= e) {
        return;
    }

    //Recursion case
    int p = partition(a, s, e);
    quick_sort(a, s, p - 1);
    quick_sort(a, p + 1, e);
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

    int n = arr.size();
    quick_sort(arr, 0, n-1);

    for(int x: arr) {
        cout << x << ",";
    }
    cout << endl;

    return 0;
}