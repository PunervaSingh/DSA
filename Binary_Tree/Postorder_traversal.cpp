#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * left;
        Node * right;

        Node(int d) {
            data = d;
            left = right = NULL;
        }
};

Node * build_tree() {
    int d;
    cin >> d;

    if(d == -1) {
        return NULL;
    }

    Node * n = new Node(d);
    n -> left = build_tree();
    n -> right = build_tree();
    return n;
}

void print_postorder(Node * root) {
    if(root == NULL) {
        return;
    }
    print_postorder(root -> left);
    print_postorder(root -> right);
    cout << root -> data << " ";
}

int main() {
    Node * root = build_tree();
    print_postorder(root);
}