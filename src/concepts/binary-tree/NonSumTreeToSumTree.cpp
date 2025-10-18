#include "BinaryTreeCommon.h"

void sumTreeCoversion(node root) {
  int lvalue = 0, rvalue = 0;
  if (root == NULL || (root->left == NULL && root->right == NULL)) return;
  sumTreeCoversion(root->left);
  sumTreeCoversion(root->right);
  if (root->left != NULL) lvalue = root->left->data;
  if (root->right != NULL) rvalue = root->right->data;
  root->data = lvalue + rvalue;
}

void inOrderTraversal(node root) {
  if (root == NULL) return;
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

int main() {
  node root = setupTree();

  cout << "Original tree (In-order): ";
  inOrderTraversal(root);
  cout << endl;

  sumTreeCoversion(root);

  cout << "After sum tree conversion (In-order): ";
  inOrderTraversal(root);
  cout << endl;

  return 0;
}
