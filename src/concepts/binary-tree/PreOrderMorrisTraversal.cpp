#include "BinaryTreeCommon.h"

void morrisPreOrder(node root){
    node current = root, tmp;
    while(current){
        if(!current->left){
            cout << current->data << " ";
            current = current->right;
        }else{
            tmp = current->left;
            while(tmp->right != NULL && tmp->right != current){
                tmp = tmp->right;
            }
            if(tmp->right == NULL){
                tmp->right = current;
                cout << current->data << " ";
                current = current->left;
            }
            else if(tmp->right == current){
                tmp->right = NULL;
                current = current->right;
            }
        }
    }
}

int main() {
    node root = setupTree();
    
    cout << "Morris Pre-order Traversal: ";
    morrisPreOrder(root);
    cout << endl;
    
    return 0;
}
