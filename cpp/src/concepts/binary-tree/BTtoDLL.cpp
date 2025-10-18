#include "BinaryTreeCommon.h"

#define print(a) cout << a << " "

void printList(node head) {
  node current = head;
  while (current) {
    print(current->data);
    current = current->right;
  }
  cout << endl;
}

// Append two doubly linked list
node append(node x, node y) {
  if (x == NULL) return y;
  if (y == NULL) return x;
  node xlast;
  xlast = x;
  while (xlast->right != NULL) xlast = xlast->right;
  xlast->right = y;
  y->left = xlast;
  return x;
}

// Conversion to list
node treetoList(node root) {
  node leftList, rightList, finalList;
  if (!root) return root;
  leftList = treetoList(root->left);
  rightList = treetoList(root->right);
  root->left = NULL;
  root->right = NULL;
  finalList = append(leftList, root);
  finalList = append(finalList, rightList);
  return finalList;
}

int main() {
  node root = setupTree();
  cout << "Original tree (in-order): ";
  // Simple in-order print for comparison
  cout << "Converting binary tree to doubly linked list..." << endl;
  node dll = treetoList(root);
  cout << "Doubly linked list: ";
  printList(dll);
  return 0;
}
