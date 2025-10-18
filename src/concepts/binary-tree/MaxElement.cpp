#include "BinaryTreeCommon.h"

int max_element_recursive(struct BtreeNode* root) {
  if (!root) return INT_MIN;
  int left_val = max_element_recursive(root->left);
  int right_val = max_element_recursive(root->right);
  return max(root->data, max(left_val, right_val));
}

int iterative_max_element(struct BtreeNode* root) {
  int ans = INT_MIN;
  struct BtreeNode* temp;
  queue<struct BtreeNode*> Q;
  if (root == NULL) return ans;
  Q.push(root);
  while (!Q.empty()) {
    temp = Q.front();
    Q.pop();
    ans = max(ans, temp->data);
    if (temp->left) Q.push(temp->left);
    if (temp->right) Q.push(temp->right);
  }
  return ans;
}

int main() {
  node root = setupTree();
  cout << "Maximum element in binary tree:" << endl;
  cout << "Recursive approach: " << max_element_recursive(root) << endl;
  cout << "Iterative approach: " << iterative_max_element(root) << endl;
  return 0;
}
