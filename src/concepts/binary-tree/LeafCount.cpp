#include "BinaryTreeCommon.h"

int count_leaf(node root)
{
    if(root==NULL)return 0;
    else if(root->left==NULL && root->right==NULL )return 1;
    else return count_leaf(root->left)+count_leaf(root->right);
}

int main() {
    node root = setupTree();
    cout << "Number of leaf nodes in binary tree: " << count_leaf(root) << endl;
    return 0;
}

