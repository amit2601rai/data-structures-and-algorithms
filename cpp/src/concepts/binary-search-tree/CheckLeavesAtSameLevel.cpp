#include "BSTCommon.h"

bool isLeavesAtSameLevel(node root, int level) {
  static int flag = -1;
  if (!root) return true;
  if (root->left == NULL && root->right == NULL) {
    if (flag == -1) {
      flag = level;
      return true;
    }
    if (flag != level) return false;
  }
  return isLeavesAtSameLevel(root->left, level + 1) && isLeavesAtSameLevel(root->right, level + 1);
}

int main() {
  node root = setupBST();

  cout << "BST In-order: ";
  inOrderTraversal(root);
  cout << endl;

  bool result = isLeavesAtSameLevel(root, 0);
  cout << "Are all leaves at same level? " << (result ? "Yes" : "No") << endl;

  return 0;
}
