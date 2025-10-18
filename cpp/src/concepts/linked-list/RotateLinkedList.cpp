#include "LinkedListCommon.h"

Node rotateLinkedList(Node head, int k) {
  if (head == NULL || k == 0) {
    return head;
  }

  // Find length and last node
  Node last = head;
  int length = 1;
  while (last->next != NULL) {
    last = last->next;
    length++;
  }

  // Optimize k
  k = k % length;
  if (k == 0) {
    return head;
  }

  // Find the (k+1)th node from beginning
  Node kthNode = head;
  for (int i = 1; i < k; i++) {
    kthNode = kthNode->next;
  }

  // The (k+1)th node becomes new head
  Node newHead = kthNode->next;

  // Break the link after kth node
  kthNode->next = NULL;

  // Connect last node to original head
  last->next = head;

  return newHead;
}

int main() {
  Node head = setupList();

  cout << "Original list: ";
  printList(head);

  int k = 2;
  head = rotateLinkedList(head, k);

  cout << "List after rotating by " << k << " positions: ";
  printList(head);

  return 0;
}
