#include "BinaryTreeCommon.h"

bool isidentical(struct BtreeNode *root1, struct BtreeNode *root2) {
  if (root1 == NULL && root2 == NULL) return true;
  if (root1 == NULL || root2 == NULL) return false;
  return ((root1->data == root2->data) && isidentical(root1->left, root2->left) &&
          isidentical(root1->right, root2->right));
}

int main() {
  node root1 = setupTree();
  node root2 = setupTree();  // Same tree

  cout << "Comparing two identical trees: " << (isidentical(root1, root2) ? "Identical" : "Not Identical") << endl;

  // Modify one tree slightly for testing
  if (root2->left) root2->left->data = 999;
  cout << "After modifying one tree: " << (isidentical(root1, root2) ? "Identical" : "Not Identical") << endl;

  return 0;
}
