#include "BinaryTreeCommon.h"

void nodesatkdis(struct BtreeNode *root, int k) {
  if (!root) return;
  if (k == 0) {
    cout << root->data << " ";
    return;
  }
  nodesatkdis(root->left, k - 1);
  nodesatkdis(root->right, k - 1);
}

int main() {
  node root = setupTree();
  int distance = 2;
  cout << "Nodes at distance " << distance << " from root: ";
  nodesatkdis(root, distance);
  cout << endl;

  distance = 3;
  cout << "Nodes at distance " << distance << " from root: ";
  nodesatkdis(root, distance);
  cout << endl;

  return 0;
}
