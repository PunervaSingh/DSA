#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> v = {1, 2, 3, 4, 5}; <---- NOT WORKING due to different cpp version, works fine in c++11----->

    // Fill constructor
    vector<int> arr(10, 7); // Will fill 10 places with value 7

    // Fill Constructor
    vector<int> visited(100, 0);

    // pop_back() - Will pop an element from the end of the vector
    arr.pop_back();

    // push_back(value) - Will add an value to the back of the mentioned vector
    arr.push_back(6);

    // size() - size of the vector / Number of elements
    cout << arr.size() << endl;

    // Capaity of the vector
    cout << arr.capacity() << endl;

    // Print all the element in the vector
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}