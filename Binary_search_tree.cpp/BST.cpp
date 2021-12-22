#include<iostream>
using namespace std;

class Node {
    public:
        int key;
        Node * left;
        Node * right;

        Node(int key) {
            this -> key = key;
            left = right = NULL;
        }
};

Node * find_min(Node * root) {
    while(root -> left != NULL) {
        root = root -> left;
    }
    return root;
}

Node * insert(Node* root, int key) {
    if(root == NULL) {
        return new Node(key);
    }
    // Recursive case
    if(key < root -> key) {
        root -> left = insert(root -> left, key);
    }
    else {
        root -> right = insert(root -> right, key);
    }
    return root;
}

void printInOrder(Node * root) {
    if(root == NULL) {
        return;
    }
    // Left, Root, Right
    printInOrder(root -> left);
    cout << root -> key << " ";
    printInOrder(root -> right);
}

// Searching in BST
// Time complexity - O(H)
bool search(Node * root, int key) {
    if(root == NULL) {
        return false;
    }
    if(root -> key == key) {
        return true;
    }
    if(key < root -> key) {
        return search(root -> left, key);
    }
    return search(root -> right, key);
}

// Deletion
Node * remove(Node * root, int key) {
    if(root == NULL) {
        return NULL;
    }
    else if(key < root -> key) {
        root -> left = remove(root -> left, key);
    }
    else if(key > root -> key) {
        root -> right = remove(root -> right, key);
    }
    else {
        // when the current node matches with the key
        // NO CHILDREN
        if(root -> left == NULL and root -> right == NULL) {
            delete root;
            root = NULL;
        }

        // SINGLE CHILD
        else if(root -> left == NULL) {
            Node * temp = root;
            root = root -> right;
            delete temp;
        }

        else if(root -> right == NULL) {
            Node * temp = root;
            root = root -> left;
            delete temp;
        }

        // 2 CHILDREN
        else {
            Node * temp = find_min(root -> right);
            root -> key = temp -> key;
            root -> right = remove(root -> right, temp -> key);
        }
    }
    return root;
}


int main() {
    Node * root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int x: arr) {
        root = insert(root, x);
    }

    printInOrder(root);

    return 0;
}