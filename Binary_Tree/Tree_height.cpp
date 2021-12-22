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

//Helper function : Height of the tree
// Time : O(N) since we are traversing whole tree
int height(node * root) {
    if(root == NULL) {
        return 0;
    }
    int h1 = height(root -> left);
    int h2 = height(root -> right);
    return 1 + max(h1, h2);
}