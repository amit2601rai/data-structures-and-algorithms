#include "BinaryTreeCommon.h"

node removeNodes(node root, int K, int &sum) {
  if (!root) return NULL;
  int lsum, rsum;
  lsum = sum + root->data;
  rsum = lsum;
  root->left = removeNodes(root->left, K, lsum);
  root->right = removeNodes(root->right, K, rsum);
  sum = max(lsum, rsum);
  if (sum < K) {
    free(root);
    root = NULL;
  }
  return root;
}

void inOrderTraversal(node root) {
  if (root == NULL) return;
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

int main() {
  node root = setupTree();
  int K = 10;  // Remove nodes with path sum less than K
  int sum = 0;

  cout << "Original tree (In-order): ";
  inOrderTraversal(root);
  cout << endl;

  root = removeNodes(root, K, sum);

  cout << "After removing nodes with path sum < " << K << " (In-order): ";
  inOrderTraversal(root);
  cout << endl;

  return 0;
}
