#include "BinaryTreeCommon.h"

int sum_element(struct BtreeNode* root){
	if(root==NULL)return 0;
	return (root->data+sum_element(root->left)+sum_element(root->right));
}

int main() {
    node root = setupTree();
    cout << "Sum of all elements in binary tree: " << sum_element(root) << endl;
    return 0;
}
