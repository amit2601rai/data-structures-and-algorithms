#include "BSTCommon.h"

struct BtreeNode *removekeys(struct BtreeNode *root,int minval,int maxval){
	if(!root)return NULL;
	root->left=removekeys(root->left,minval,maxval);
	root->right=removekeys(root->right,minval,maxval);
	struct BtreeNode *child;
	if(root->data < minval){
		child=root->right;
		free(root);
		return child;
	}
	else if(root->data >maxval){
		child=root->left;
		free(root);
		return child;
	}
	else return root;
}

int main() {
    node root = setupBST();
    
    cout << "Original BST: ";
    inOrderTraversal(root);
    cout << endl;
    
    int minval = 30, maxval = 60;
    root = removekeys(root, minval, maxval);
    
    cout << "After removing keys outside range [" << minval << ", " << maxval << "]: ";
    inOrderTraversal(root);
    cout << endl;
    
    return 0;
}
