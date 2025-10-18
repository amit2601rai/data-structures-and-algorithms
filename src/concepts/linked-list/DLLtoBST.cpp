#include "LinkedListCommon.h"

void inorderBST(Dnode root) {
  if (root) {
    inorderBST(root->prev);
    cout << root->data << " ";
    inorderBST(root->next);
  }
}

int countNodes(Dnode head) {
  int nodeCount = 0;
  while (head) {
    nodeCount++;
    head = head->next;
  }
  return nodeCount;
}

Dnode dllToBSTUtil(Dnode* head_ref, int n) {
  if (n <= 0) return NULL;

  Dnode left = dllToBSTUtil(head_ref, n / 2);

  Dnode root = *head_ref;
  root->prev = left;

  *head_ref = (*head_ref)->next;

  root->next = dllToBSTUtil(head_ref, n - n / 2 - 1);

  return root;
}

Dnode dllToBST(Dnode head) {
  int n = countNodes(head);
  return dllToBSTUtil(&head, n);
}

int main() {
  // Create a sorted doubly linked list: 1<->2<->3<->4<->5
  Dnode head = getNewDnode(1);
  head->next = getNewDnode(2);
  head->next->prev = head;
  head->next->next = getNewDnode(3);
  head->next->next->prev = head->next;
  head->next->next->next = getNewDnode(4);
  head->next->next->next->prev = head->next->next;
  head->next->next->next->next = getNewDnode(5);
  head->next->next->next->next->prev = head->next->next->next;

  cout << "Original doubly linked list: ";
  printDList(head);

  Dnode bstRoot = dllToBST(head);

  cout << "Inorder traversal of BST: ";
  inorderBST(bstRoot);
  cout << endl;

  return 0;
}
