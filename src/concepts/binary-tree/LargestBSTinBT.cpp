#include "BinaryTreeCommon.h"

int largestBSTinBTUtil(node root, int &maxValue, int &minValue, int &maxNodes, node &largestBST) {
  if (!root) return 0;
  bool isBST = true;
  int curMinVal, curMaxVal, totalNodes;

  int leftNodes = largestBSTinBTUtil(root->left, maxValue, minValue, maxNodes, largestBST);
  curMinVal = (leftNodes == 0) ? root->data : minValue;
  if (leftNodes == -1 || ((leftNodes != 0) && root->data <= maxValue)) isBST = false;

  int rightNodes = largestBSTinBTUtil(root->right, maxValue, minValue, maxNodes, largestBST);
  curMaxVal = (rightNodes == 0) ? root->data : maxValue;
  if (rightNodes == -1 || ((rightNodes != 0) && root->data >= minValue)) isBST = false;

  if (isBST) {
    minValue = curMinVal;
    maxValue = curMaxVal;
    totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      largestBST = root;
      maxNodes = totalNodes;
    }
    return totalNodes;
  }
  return -1;
}

node largestBSTinBT(node root) {
  // For a particular subtree root at let's say A, minValue is minimum value in that subtree and maxValue is maximum
  // value in that subtree
  int minValue = INT_MAX, maxValue = INT_MIN, maxNodes = INT_MIN;
  node largestBST = NULL;
  largestBSTinBTUtil(root, maxValue, minValue, maxNodes, largestBST);
  return largestBST;
}

int main() {
  node root = setupTree();
  node result = largestBSTinBT(root);

  if (result) {
    cout << "Root of largest BST in the tree: " << result->data << endl;
  } else {
    cout << "No BST found in the tree" << endl;
  }

  return 0;
}
