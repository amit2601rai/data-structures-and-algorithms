#include "BinaryTreeCommon.h"

// Height function needed for diameter calculation
int height(struct BtreeNode* root) {
  if (root == NULL || (root->left == NULL && root->right == NULL))
    return 0;
  else
    return (max(height(root->left), height(root->right)) + 1);
}

int diameter(struct BtreeNode* root) {
  if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
  return (max(diameter(root->left), max(diameter(root->right), height(root->left) + height(root->right) +
                                                                   (root->left != NULL) + (root->right != NULL))));
}

/*Optimized Diameter Approach*/
int diameterOpt(struct BtreeNode* root, int& ans) {
  if (!root) return 0;
  int lh = diameterOpt(root->left, ans);
  int rh = diameterOpt(root->right, ans);
  ans = max(ans, lh + rh + 1);
  return max(lh, rh) + 1;
}

int main() {
  node root = setupTree();
  cout << "Diameter of binary tree:" << endl;
  cout << "Basic approach: " << diameter(root) << endl;

  int ans = INT_MIN;
  diameterOpt(root, ans);
  cout << "Optimized approach: " << ans << endl;

  return 0;
}
