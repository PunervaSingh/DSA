#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node * left;
        node * right;

        node(int d) {
            data = d;
            left = right = NULL;
        }
};

int height(node * root) {
    if(root == NULL) {
        return 0;
    }
    int h1 = height(root -> left);
    int h2 = height(root -> right);
    return 1 + max(h1, h2);
}

// Tree diameter - Diameter is defined as the largest distance between any two nodes of the tree.
// Time complexity -> O(N^2)
int diameter(node * root) {
    // Base case
    if(root == NULL) {
        return 0;
    }
    int d1 = height(root -> left) + height(root -> right);
    int d2 = diameter(root -> left);
    int d3 = diameter(root -> right);
    return max(d1, max(d2, d3));
}