#include "BinaryTreeCommon.h"

void printArray(int path[], int pathLen) {
  for (int i = 0; i < pathLen; i++) {
    cout << path[i] << " ";
  }
  cout << endl;
}

void printRootToLeafPaths(node root, int path[], int pathLen) {
  if (root == NULL) {
    return;
  }

  // Add current node to path
  path[pathLen] = root->data;
  pathLen++;

  // If it's a leaf, print the path
  if (root->left == NULL && root->right == NULL) {
    printArray(path, pathLen);
  } else {
    // Recur for left and right subtrees
    printRootToLeafPaths(root->left, path, pathLen);
    printRootToLeafPaths(root->right, path, pathLen);
  }
}

int main() {
  node root = setupTree();
  int path[1000];  // Assuming maximum depth of 1000

  cout << "All root to leaf paths:" << endl;
  printRootToLeafPaths(root, path, 0);

  return 0;
}
