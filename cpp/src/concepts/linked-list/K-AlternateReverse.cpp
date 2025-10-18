#include "LinkedListCommon.h"

bool hasKNodes(Node root, int k) {
  int count = 0;
  while (root && count < k) {
    count++;
    root = root->next;
  }
  return (count == k);
}

Node kAlternateReverse(Node head, int k, bool shouldReverse) {
  if (head == NULL) {
    return NULL;
  }

  if (!hasKNodes(head, k)) {
    return head;
  }

  Node prev, cur, next, temp;
  int count = k;

  if (shouldReverse) {
    // Reverse first k nodes
    temp = head;
    prev = NULL;
    cur = head;

    while (count-- && cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    // Recursively process remaining list without reversing next k nodes
    temp->next = kAlternateReverse(cur, k, false);
    return prev;
  } else {
    // Skip next k nodes without reversing
    cur = head;
    while (count-- && cur) {
      prev = cur;
      cur = cur->next;
    }

    // Recursively process remaining list and reverse next k nodes
    prev->next = kAlternateReverse(cur, k, true);
    return head;
  }
}

int main() {
  Node head = setupList();

  cout << "Original list: ";
  printList(head);

  int k = 2;
  head = kAlternateReverse(head, k, true);  // Start with reversing

  cout << "After alternate k-reverse with k=" << k << ": ";
  printList(head);

  return 0;
}
