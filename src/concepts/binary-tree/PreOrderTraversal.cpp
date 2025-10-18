#include "BinaryTreeCommon.h"

#define print(a) cout << a << " "

// Recursive
void rPreOrder(node root) {
  if (root) {
    print(root->data);
    rPreOrder(root->left);
    rPreOrder(root->right);
  }
}

// Iterative-I
void iPreOrder(node root) {
  if (!root) return;
  stack<node> s;
  do {
    while (root) {
      s.push(root);
      print(root->data);
      root = root->left;
    }
    root = s.top();
    s.pop();
    root = root->right;
  } while (root || !s.empty());
}

void preorder(node root) {
  cout << "Recursive:" << endl;
  rPreOrder(root);
  cout << endl;
  cout << "Iterative-I:" << endl;
  iPreOrder(root);
  cout << endl;
}

int main() {
  node root = setupTree();
  preorder(root);
  return 0;
}
