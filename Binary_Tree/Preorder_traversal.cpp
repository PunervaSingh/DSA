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

// Preoreder Build of the tree - Root, left child node, right child node.
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

void print_preorder(Node * root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    print_preorder(root -> left);
    print_preorder(root -> right);
}

int main() {
    Node * root = build_tree();
    print_preorder(root);
}