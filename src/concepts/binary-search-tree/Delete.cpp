#include "BSTCommon.h"

/** Getting InOrder Successor **/
node getInorderSuccessor(node root){
    node result;
    while(root){
        result = root;
        root = root->left;
    }
return result;
}

/** Deletion Of Node In BST **/
node del(node root, int key){
    if(!root) return root;
    if(key < root->data) root->left = del(root->left, key);
    else if(key > root->data) root->right = del(root->right, key);
    else if (key == root->data){
         if(root->left == NULL){
             node tmp = root->right;
             free(root);
             return tmp;
        }else if(root->right == NULL){
             node tmp = root->left;
             free(root);
             return tmp;
        }else{
            node tmp = getInorderSuccessor(root->right);
            swap(tmp->data, root->data);
            root->right = del(root->right, key);
        }
    }
return root;
}

int main() {
    node root = setupBST();
    
    cout << "Original BST: ";
    inOrderTraversal(root);
    cout << endl;
    
    cout << "Deleting 30: ";
    root = del(root, 30);
    inOrderTraversal(root);
    cout << endl;
    
    cout << "Deleting 50: ";
    root = del(root, 50);
    inOrderTraversal(root);
    cout << endl;
    
    return 0;
}
