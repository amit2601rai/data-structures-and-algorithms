#include "BSTCommon.h"

node insert(node root,int x ){
	if(root==NULL){
	    node tmp = getNewNode(x);
	    root=tmp;
	}
	else{
   		if(x <= root->data) root->left=insert(root->left,x);
   		else root->right=insert(root->right,x);
       }
return root;
}

int main() {
    node root = NULL;
    
    cout << "Inserting elements: 50, 30, 70, 20, 40, 60, 80" << endl;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    cout << "BST In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    
    cout << "Inserting 25: ";
    root = insert(root, 25);
    inOrderTraversal(root);
    cout << endl;
    
    return 0;
}
