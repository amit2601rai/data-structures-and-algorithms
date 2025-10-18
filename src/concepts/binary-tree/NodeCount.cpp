#include "BinaryTreeCommon.h"

int count_nodes(struct BtreeNode* root) {
  if (root == NULL) return 0;
  return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int main() {
  node root = setupTree();
  cout << "Total number of nodes in binary tree: " << count_nodes(root) << endl;
  return 0;
}
