#include "BSTCommon.h"

void addAllGreaterElement(node root) {
  static int value = 0;
  if (root) {
    addAllGreaterElement(root->right);
    root->data += value;
    value = root->data;
    addAllGreaterElement(root->left);
  }
}

int main() {
  node root = setupBST();

  cout << "Original BST: ";
  inOrderTraversal(root);
  cout << endl;

  addAllGreaterElement(root);

  cout << "After adding greater elements: ";
  inOrderTraversal(root);
  cout << endl;

  return 0;
}
