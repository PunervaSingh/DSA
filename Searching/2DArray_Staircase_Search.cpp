// SORTED 2D ARRAY SEARCH CODE
#include<iostream>
using namespace std;

pair<int, int> staircase_search(int arr[][4], int n, int m, int key) {
    // Later if the element is not present return {-1, -1}
    pair<int, int> ans(-1, -1);

    if(key < arr[0][0] || key > arr[n-1][m-1]) {
        return ans;
    }

    // Staircase Search
    int i = 0;
    int j = m - 1;
     
    while(i <= n -1 && j >= 0) {
        if(arr[i][j] == key) {
            ans.first = i;
            ans.second = j;
            return ans;
        }
        else if(arr[i][j] > key) {
            j--;
        }
        else{
            i++;
        }
    }
    return ans;
}

int main() {
    //2D Row & Column wise sorted array
    int arr[][4] = {{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50}};
    int n = 4, m = 4;
    pair<int, int> coords = staircase_search(arr, n, m, 55);
    cout << coords.first << " " << coords.second << endl;

    return 0;
}