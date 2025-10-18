#include "BSTCommon.h"

void keysinrange(struct BtreeNode *root,int k1,int k2){
	if(!root)return ;
	if(root->data<k1)keysinrange(root->right,k1,k2);
	else if(root->data>k2)keysinrange(root->left,k1,k2);
	else if(root->data>=k1 && root->data<=k2){
		cout<<root->data<<" ";
		keysinrange(root->left,k1,k2);
		keysinrange(root->right,k1,k2);
	}
}

int main() {
    node root = setupBST();
    
    cout << "BST In-order: ";
    inOrderTraversal(root);
    cout << endl;
    
    int k1 = 30, k2 = 60;
    cout << "Keys in range [" << k1 << ", " << k2 << "]: ";
    keysinrange(root, k1, k2);
    cout << endl;
    
    return 0;
}
