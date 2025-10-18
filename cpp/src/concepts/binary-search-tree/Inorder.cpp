#include "BSTCommon.h"

void inorder(struct BtreeNode *root) {
  if (root) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

int main() {
  node root = setupBST();

  cout << "BST In-order traversal: ";
  inorder(root);
  cout << endl;

  return 0;
}
