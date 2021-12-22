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

void print_Inorder(Node * root) {
    if(root == NULL) {
        return;
    }
    print_Inorder(root -> left);
    cout << root -> data << " ";
    print_Inorder(root -> right);
}

int main() {
    Node * root = build_tree();
    print_Inorder(root);
}