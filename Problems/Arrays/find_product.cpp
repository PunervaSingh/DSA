/*
Implement a function, findProduct(int arr[], int size) which takes an array arr and its size as an input and 
returns an array so that each index has a product of all the numbers present in the array except the number 
stored at that index.

size should be equal to or greater than 2.

Input
arr = [1,2,3,4]
Output
arr = [24,12,8,6]
*/

#include <iostream>
using namespace std;

/*
Method 1 - Brute force Approach - O(n^2)
Using two for loop, if index o first loop matches with the index of inneer loop then do nothing.
Else multiply to prod variable and after traversing for each index store it in the array.
*/
// int *findProduct(int arr[], int size)
// {
//     int *product = new int[size];
//     for (int i = 0; i < size; i++)
//     {
//         int prod = 1;
//         for (int j = 0; j < size; j++)
//         {
//             if (i != j)
//                 prod *= arr[j];
//         }
//         product[i] = prod;
//     }
//     return product;
// }

/*
Method 2 - Time Complexity - O(n)
traverse whole array and get product of all elements in the array. Store resultant product in a variable.
Then traverse the array again and divide product variable with the element present at the index and store 
resultant in the array.
*/
// int * findProduct(int arr[], int size)  { 
//     int * product = new int[size];
//     int prod = 1;
//     for(int i = 0; i < size; i++) prod *= arr[i];
//     for(int i = 0; i < size; i++) product[i] = prod/arr[i];
//     return product;
// }


/*
Method 3 - Time Complexity - O(n) [If division is not allowed]
Make two extra arrays to store prefix and suffix uptil the given position from left and right side respectively.
Then traverse the array and store product of suffix and prefix at the given position.
*/
int * findProduct(int arr[], int size)  { 
    int * prefix = new int[size];
    int * suffix = new int[size];
    int * product = new int[size];
    prefix[0] = arr[0];
    for(int i = 1; i < size; i++) {
        prefix[i] = arr[i] * prefix[i-1];
    }
    suffix[size - 1] = arr[size - 1];
    for(int i = size - 2; i >= 0; i--) {
        suffix[i] = arr[i] * suffix[i + 1];
    }
    for(int i = 0; i < size; i++) {
        if(i == 0) { 
            product[i] = 1 * suffix[i + 1];
        } else if(i == size - 1) {
            product[i] = prefix[i - 1] * 1;
        } else {
            product[i] = prefix[i - 1] * suffix[i + 1];
        }
    }
    return product;
} 

int main() {
    int size = 4;
    int arr[] = {1, 3, 4, 5}; // 60 20 15 12 

    int *prodArray = findProduct(arr, size);

    for (int i = 0; i < size; i++) {
        cout << prodArray[i] << " ";
    }
    cout << endl;
    delete[] prodArray;
    return 0;
}