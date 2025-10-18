#include "BSTCommon.h"

node sortedArrayToBst(int a[], int low, int high) {
  if (low > high) return NULL;
  int mid = (low + high) / 2;
  node root = getNewNode(a[mid]);
  root->left = sortedArrayToBst(a, low, mid - 1);
  root->right = sortedArrayToBst(a, mid + 1, high);
  return root;
}

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60, 70};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Sorted Array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  node root = sortedArrayToBst(arr, 0, n - 1);

  cout << "BST from sorted array (In-order): ";
  inOrderTraversal(root);
  cout << endl;

  return 0;
}
