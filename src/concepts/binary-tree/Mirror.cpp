#include "BinaryTreeCommon.h"

void mirror(struct BtreeNode* root){
	if(root){
        mirror(root->left);
        mirror(root->right);
        struct BtreeNode *temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}

void inOrderPrint(struct BtreeNode* root) {
    if(root) {
        inOrderPrint(root->left);
        cout << root->data << " ";
        inOrderPrint(root->right);
    }
}

int main() {
    node root = setupTree();
    cout << "Original tree (in-order): ";
    inOrderPrint(root);
    cout << endl;
    
    mirror(root);
    cout << "Mirrored tree (in-order): ";
    inOrderPrint(root);
    cout << endl;
    
    return 0;
}


