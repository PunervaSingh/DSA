#include<iostream>
using namespace std;

int main(){
    // Creating an array of size total_students 
    // Initializing it with value 0 so that all garbage values of the array are replaced by 0. 
    int marks[100] = {0};

    int total_students = 0;
    cout << "Enter number of students: ";
    cin >> total_students;

    // Input values in the array
    cout << "Enter marks of " << total_students << " students: ";
    for(int i = 0; i < total_students; i++) {
        cin >> marks[i];
    }

    // Updating value of first element of the array
    cout << "Updating value of the firt element to 20" << endl;
    marks[0] = 20;

    // Output values stored in the array
    cout << "Marks of students: ";
    for(int i = 0; i < total_students; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;
}