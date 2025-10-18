#include "BSTCommon.h"

/** Is there any pair exists such that sum of two elements is SUM **/
bool isPairSum(node root, int SUM) {
  stack<node> leftSide;
  stack<node> rightSide;
  node root1 = root;
  node root2 = root;
  bool leftFlag, rightFlag;
  leftFlag = rightFlag = true;
  node leftV, rightV;
  while (true) {
    // Iterative Inorder From Left Side
    do {
      if (!leftFlag) break;
      while (root1) {
        leftSide.push(root1);
        root1 = root1->left;
      }
      node tmp = leftSide.top();
      leftSide.pop();
      if (tmp) {
        leftV = tmp;
        leftFlag = false;
        if (tmp->right) root1 = tmp->right;
      }
    } while (root1 || !leftSide.empty());

    // Iterative Inorder From Right Side
    do {
      if (!rightFlag) break;
      while (root2) {
        rightSide.push(root2);
        root2 = root2->right;
      }
      node tmp = rightSide.top();
      rightSide.pop();
      if (tmp) {
        rightV = tmp;
        rightFlag = false;
        if (tmp->left) root2 = tmp->left;
      }
    } while (root2 || !rightSide.empty());

    if (leftV->data + rightV->data == SUM)
      return true;
    else if (leftV->data + rightV->data < SUM)
      leftFlag = true;
    else
      rightFlag = true;
    if (leftV == rightV) break;
  }
  return false;
}

int main() {
  node root = setupBST();

  cout << "BST In-order: ";
  inOrderTraversal(root);
  cout << endl;

  int target = 90;
  bool result = isPairSum(root, target);
  cout << "Is there a pair with sum " << target << "? " << (result ? "Yes" : "No") << endl;

  target = 110;
  result = isPairSum(root, target);
  cout << "Is there a pair with sum " << target << "? " << (result ? "Yes" : "No") << endl;

  return 0;
}
