#include "BinaryTreeCommon.h"

void deepestLeftLeaf(node root, int level, bool isLeft, node &result) {
  static int max_level = -1;
  if (!root) return;
  if (isLeft && root->left == NULL && root->right == NULL) {
    if (max_level < level) {
      max_level = level;
      result = root;
    }
    return;
  }
  deepestLeftLeaf(root->left, level + 1, true, result);
  deepestLeftLeaf(root->right, level + 1, false, result);
}

int main() {
  node root = setupTree();
  node result = NULL;
  deepestLeftLeaf(root, 0, false, result);

  if (result) {
    cout << "Deepest left leaf: " << result->data << endl;
  } else {
    cout << "No left leaf found" << endl;
  }

  return 0;
}
