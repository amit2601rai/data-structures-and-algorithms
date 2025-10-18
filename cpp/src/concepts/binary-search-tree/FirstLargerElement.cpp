#include "BSTCommon.h"

void firstLargerElement(node root, int key, int *ans) {
  if (root == NULL) return;
  if (root->data > key) {
    *ans = root->data;
    firstLargerElement(root->left, key, ans);
  } else
    firstLargerElement(root->right, key, ans);
}

int main() {
  node root = setupBST();

  cout << "BST In-order: ";
  inOrderTraversal(root);
  cout << endl;

  int key = 35;
  int ans = -1;
  firstLargerElement(root, key, &ans);
  cout << "First larger element than " << key << ": " << ans << endl;

  key = 65;
  ans = -1;
  firstLargerElement(root, key, &ans);
  cout << "First larger element than " << key << ": " << ans << endl;

  return 0;
}
