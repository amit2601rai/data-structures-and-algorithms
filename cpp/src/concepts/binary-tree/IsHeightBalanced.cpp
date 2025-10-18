#include "BinaryTreeCommon.h"

// Height function for balance checking
int height(struct BtreeNode* root) {
  if (root == NULL) return 0;
  return 1 + max(height(root->left), height(root->right));
}

int height_balanced(struct BtreeNode* root) {
  if (root == NULL)
    return 1;
  else {
    int l = height(root->left);
    int h = height(root->right);
    return (abs(l - h) <= 1 && height_balanced(root->left) && height_balanced(root->right));
  }
}

int main() {
  node root = setupTree();
  cout << "Is the tree height balanced? " << (height_balanced(root) ? "Yes" : "No") << endl;

  // Create an unbalanced tree for comparison
  node unbalanced = getNewNode();
  unbalanced->data = 1;
  unbalanced->left = getNewNode();
  unbalanced->left->data = 2;
  unbalanced->left->left = getNewNode();
  unbalanced->left->left->data = 3;

  cout << "Is the unbalanced tree height balanced? " << (height_balanced(unbalanced) ? "Yes" : "No") << endl;

  return 0;
}
