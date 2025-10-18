#include "BinaryTreeCommon.h"

int searchKey(int a[], int key, int low, int high) {
  for (int i = low; i <= high; i++)
    if (key == a[i]) return i;
  return -1;  // key not found
}

node treeFromPreOrderInOrder(int Pre[], int In[], int &index, int low, int high) {
  if (low > high) return NULL;
  int tmpIndex = searchKey(In, Pre[index++], low, high);
  node root = (node)malloc(sizeof(struct BtreeNode));
  root->data = In[tmpIndex];
  root->left = NULL;
  root->right = NULL;
  root->left = treeFromPreOrderInOrder(Pre, In, index, low, tmpIndex - 1);
  root->right = treeFromPreOrderInOrder(Pre, In, index, tmpIndex + 1, high);
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
  int Pre[n];
  int In[n];
  cout << "Enter preorder array: ";
  for (int i = 0; i < n; i++) cin >> Pre[i];
  cout << "Enter inorder array: ";
  for (int i = 0; i < n; i++) cin >> In[i];

  int index = 0;
  node root = treeFromPreOrderInOrder(Pre, In, index, 0, n - 1);

  cout << "Constructed tree (inorder): ";
  inOrderTraversal(root);
  cout << endl;

  return 0;
}
