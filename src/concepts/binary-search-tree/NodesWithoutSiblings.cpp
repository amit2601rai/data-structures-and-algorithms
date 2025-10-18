#include "BSTCommon.h"

void nodesWithoutSiblings(node root){
    if(!root)return;
    if(root->left != NULL && root->right == NULL){
        cout<<root->left->data<<" ";
        nodesWithoutSiblings(root->left);
    }
    else if(root->left == NULL && root->right != NULL){
        cout<<root->right->data<<" ";
        nodesWithoutSiblings(root->right);
    }
    else{
        nodesWithoutSiblings(root->left);
        nodesWithoutSiblings(root->right);
    }
}

int main() {
    node root = setupBST();
    
    cout << "BST In-order: ";
    inOrderTraversal(root);
    cout << endl;
    
    cout << "Nodes without siblings: ";
    nodesWithoutSiblings(root);
    cout << endl;
    
    return 0;
}
