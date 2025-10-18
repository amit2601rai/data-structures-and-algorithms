#include "BSTCommon.h"

int KthSmallestElement(node root,int &K){
    if(root){
        int left_result = KthSmallestElement(root->left,K);
        if(left_result != -1) return left_result;
        K--;
        if(K == 0)return root->data;
        return KthSmallestElement(root->right,K);
    }
    return -1;
}

int main() {
    node root = setupBST();
    
    cout << "BST In-order: ";
    inOrderTraversal(root);
    cout << endl;
    
    int k = 3;
    int temp_k = k;
    int result = KthSmallestElement(root, temp_k);
    cout << k << "rd smallest element: " << result << endl;
    
    k = 5;
    temp_k = k;
    result = KthSmallestElement(root, temp_k);
    cout << k << "th smallest element: " << result << endl;
    
    return 0;
}
