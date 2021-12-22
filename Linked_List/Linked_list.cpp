#include<iostream>
#include "list.h"
using namespace std;

int main() {
    List l;
    l.push_back(1);
    l.push_back(0);
    l.push_back(2);

    Node * temp = l.get_head();
    while(temp != NULL) {
        cout << temp -> getData() << endl;
        temp = temp -> next;
    }
    cout << endl;

    return 0;
}