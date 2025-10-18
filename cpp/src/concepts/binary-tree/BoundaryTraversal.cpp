#include "BinaryTreeCommon.h"

void pleafs(struct BtreeNode *root) {
  if (!root) return;
  if (root->left == NULL && root->right == NULL) cout << root->data << " ";
  pleafs(root->left);
  pleafs(root->right);
}

void pright(struct BtreeNode *root) {
  stack<int> s;
  while (root) {
    if (!(root->left == NULL && root->right == NULL)) s.push(root->data);
    root = root->right;
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}

void pleft(struct BtreeNode *root) {
  while (root) {
    if (!(root->left == NULL && root->right == NULL)) cout << root->data << " ";
    root = root->left;
  }
}

void btraversal(struct BtreeNode *root) {
  if (!root) return;
  cout << root->data << " ";
  pleft(root->left);
  pleafs(root->left);
  pleafs(root->right);
  pright(root->right);
  cout << endl;
}

int main() {
  node root = setupTree();
  cout << "Boundary Traversal: ";
  btraversal(root);
  return 0;
}
