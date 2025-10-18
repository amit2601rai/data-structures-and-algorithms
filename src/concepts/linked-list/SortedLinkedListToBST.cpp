#include "LinkedListCommon.h"

int countNodes(Node head) {
  int nodeCount = 0;
  while (head) {
    nodeCount++;
    head = head->next;
  }
  return nodeCount;
}

// Using double pointer approach
Dnode sortedLLToBSTUtil(Node* head_ref, int n) {
  if (n <= 0) return NULL;

  Dnode left = sortedLLToBSTUtil(head_ref, n / 2);

  Dnode root = getNewDnode((*head_ref)->data);
  root->prev = left;  // left child

  *head_ref = (*head_ref)->next;

  root->next = sortedLLToBSTUtil(head_ref, n - n / 2 - 1);  // right child

  return root;
}

// Using reference approach
Dnode sortedLLToBSTUtil2(Node& head_ref, int n) {
  if (n <= 0) return NULL;

  Dnode left = sortedLLToBSTUtil2(head_ref, n / 2);

  Dnode root = getNewDnode(head_ref->data);
  root->prev = left;  // left child

  head_ref = head_ref->next;

  root->next = sortedLLToBSTUtil2(head_ref, n - n / 2 - 1);  // right child

  return root;
}

void inorderBST(Dnode root) {
  if (root) {
    inorderBST(root->prev);  // left
    cout << root->data << " ";
    inorderBST(root->next);  // right
  }
}

void preorderBST(Dnode root) {
  if (root) {
    cout << root->data << " ";
    preorderBST(root->prev);  // left
    preorderBST(root->next);  // right
  }
}

Dnode sortedLLToBST(Node head) {
  int n = countNodes(head);
  return sortedLLToBSTUtil(&head, n);
}

int main() {
  // Create a sorted linked list: 1->2->3->4->5->6->7
  Node head = getNewNode(1);
  Node current = head;
  for (int i = 2; i <= 7; i++) {
    current->next = getNewNode(i);
    current = current->next;
  }

  cout << "Original sorted linked list: ";
  printList(head);

  Dnode bstRoot = sortedLLToBST(head);

  cout << "Inorder traversal of BST (should be same as original list): ";
  inorderBST(bstRoot);
  cout << endl;

  cout << "Preorder traversal of BST: ";
  preorderBST(bstRoot);
  cout << endl;

  return 0;
}
