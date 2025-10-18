#include "BinaryTreeCommon.h"

bool isChildrenSum(node root){
	if(!root)
		return true;
    // Leaf nodes satisfy the property
    if(!root->left && !root->right)
        return true;
        
    int lvalue=0,rvalue=0;
	if(root->left)
        lvalue = root->left->data;
    if(root->right)
        rvalue = root->right->data;
    return (lvalue+rvalue == root->data && isChildrenSum(root->left) && isChildrenSum(root->right));
}

int main() {
    node root = setupTree();
    cout << "Is the tree a sum tree (children sum property)? " << (isChildrenSum(root) ? "Yes" : "No") << endl;
    
    // Create a simple sum tree for testing
    node sumTree = getNewNode();
    sumTree->data = 10;
    sumTree->left = getNewNode();
    sumTree->left->data = 4;
    sumTree->right = getNewNode();
    sumTree->right->data = 6;
    
    cout << "Is the simple sum tree a sum tree? " << (isChildrenSum(sumTree) ? "Yes" : "No") << endl;
    
    return 0;
}
