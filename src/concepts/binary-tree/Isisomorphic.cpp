#include "BinaryTreeCommon.h"

bool Isisomorphic(struct BtreeNode *root1, struct BtreeNode *root2) {
  if (root1 == NULL && root2 == NULL) return true;
  if (root1 == NULL || root2 == NULL) return false;
  if (root1->data != root2->data) return false;
  return ((Isisomorphic(root1->left, root2->left) && Isisomorphic(root1->right, root2->right)) ||
          (Isisomorphic(root1->right, root2->left) && Isisomorphic(root1->left, root2->right)));
}

int main() {
  node root1 = setupTree();
  node root2 = setupTree();  // Same tree

  cout << "Are the trees isomorphic? " << (Isisomorphic(root1, root2) ? "Yes" : "No") << endl;

  // Create a different tree for testing
  node diffTree = getNewNode();
  diffTree->data = 21;
  diffTree->left = getNewNode();
  diffTree->left->data = 29;  // Swapped children
  diffTree->right = getNewNode();
  diffTree->right->data = 12;

  cout << "Are the original and modified trees isomorphic? " << (Isisomorphic(root1, diffTree) ? "Yes" : "No") << endl;

  return 0;
}
