#include "BinaryTreeCommon.h"

#define print(a) cout<<a<<" "

void morrisInOrder(node root){
    node current = root, tmp;
    while(current){
        if(current->left == NULL){
            print(current->data);
            current = current->right;
        }else{
            tmp = current->left;
            while(tmp->right != NULL && tmp->right != current)
                tmp = tmp->right;
            if(tmp->right == NULL){
                tmp->right = current;
                current = current->left;
            }
            else if(tmp->right == current){
                print(current->data);
                tmp->right = NULL;
                current = current->right;
            }
        }
    }
}

int main() {
    node root = setupTree();
    cout << "Morris In-Order Traversal (O(1) space): ";
    morrisInOrder(root);
    cout << endl;
    return 0;
}
