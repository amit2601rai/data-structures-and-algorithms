#include "BinaryTreeCommon.h"

bool isBST(struct BtreeNode *root, int minval, int maxval) {
  if (!root) return true;
  if (root->data < minval || root->data > maxval) return false;
  return (isBST(root->left, minval, root->data - 1) && isBST(root->right, root->data + 1, maxval));
}

int main() {
  node root = setupTree();
  cout << "Is the tree a Binary Search Tree? " << (isBST(root, INT_MIN, INT_MAX) ? "Yes" : "No") << endl;

  // Create a simple BST for comparison
  node bst = getNewNode();
  bst->data = 20;
  bst->left = getNewNode();
  bst->left->data = 10;
  bst->right = getNewNode();
  bst->right->data = 30;

  cout << "Is the simple BST a Binary Search Tree? " << (isBST(bst, INT_MIN, INT_MAX) ? "Yes" : "No") << endl;

  return 0;
}
