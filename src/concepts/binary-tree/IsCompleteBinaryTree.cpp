#include "BinaryTreeCommon.h"

bool isCompleteBT(node root){
    if(!root) return true;
    queue<node>Q;
    Q.push(root);
    bool flag = false;
    while(!Q.empty()){
        node tmp = Q.front();
        Q.pop();
        if(tmp && flag) return false;
        if(!tmp) flag = true;
        if(tmp) Q.push(tmp->left);
        if(tmp) Q.push(tmp->right);
    }
return true;
}

int main() {
    node root = setupTree();
    cout << "Is the tree a complete binary tree? " << (isCompleteBT(root) ? "Yes" : "No") << endl;
    
    // Create a simple complete binary tree for testing
    node completeTree = getNewNode();
    completeTree->data = 1;
    completeTree->left = getNewNode();
    completeTree->left->data = 2;
    completeTree->right = getNewNode();
    completeTree->right->data = 3;
    completeTree->left->left = getNewNode();
    completeTree->left->left->data = 4;
    
    cout << "Is the simple complete tree a complete binary tree? " << (isCompleteBT(completeTree) ? "Yes" : "No") << endl;
    
    return 0;
}
