#include "BinaryTreeCommon.h"

int height(struct BtreeNode* root){
	if(root==NULL || (root->left==NULL&&root->right==NULL)) return 0; //tree with one node (or no node) has height zero
	else return(max(height(root->left),height(root->right))+1);
}

int main() {
    node root = setupTree();
    cout << "Height of the binary tree: " << height(root) << endl;
    return 0;
}
