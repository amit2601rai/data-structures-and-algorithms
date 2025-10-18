#include "BinaryTreeCommon.h"

int searchKey(int a[], int key, int low, int high) {
  for (int i = low; i <= high; i++)
    if (key == a[i]) return i;
  return -1;  // key not found
}

node treeFromPostOrderInOrder(int Post[], int In[], int &index, int low, int high) {
  if (low > high) return NULL;
  int tmpIndex = searchKey(In, Post[index--], low, high);
  node root = (node)malloc(sizeof(struct BtreeNode));
  root->data = In[tmpIndex];
  root->left = NULL;
  root->right = NULL;
  root->right = treeFromPostOrderInOrder(Post, In, index, tmpIndex + 1, high);
  root->left = treeFromPostOrderInOrder(Post, In, index, low, tmpIndex - 1);
  return root;
}

void inOrderTraversal(node root) {
  if (root == NULL) return;
  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

int main() {
  int n;
  cout << "Enter number of nodes: ";
  cin >> n;
  int Post[n];
  int In[n];
  cout << "Enter postorder array: ";
  for (int i = 0; i < n; i++) cin >> Post[i];
  cout << "Enter inorder array: ";
  for (int i = 0; i < n; i++) cin >> In[i];

  int index = n - 1;
  node root = treeFromPostOrderInOrder(Post, In, index, 0, n - 1);

  cout << "Constructed tree (inorder): ";
  inOrderTraversal(root);
  cout << endl;

  return 0;
}
