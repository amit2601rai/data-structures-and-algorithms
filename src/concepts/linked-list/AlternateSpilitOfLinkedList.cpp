#include "LinkedListCommon.h"

Node splitAlternate(Node head, Node* secondHead) {
  if (head == NULL) {
    *secondHead = NULL;
    return head;
  }

  Node prev = head;
  Node cur = prev->next;
  Node secondLast = NULL;
  *secondHead = NULL;

  while (cur != NULL) {
    prev->next = cur->next;
    Node next = cur->next;
    cur->next = NULL;

    if (*secondHead == NULL) {
      *secondHead = secondLast = cur;
    } else {
      secondLast->next = cur;
      secondLast = cur;
    }

    if (prev->next != NULL) {
      prev = prev->next;
      cur = prev->next;
    } else {
      break;
    }
  }

  return head;
}

int main() {
  Node head = setupList();
  Node secondHead = NULL;

  cout << "Original list: ";
  printList(head);

  head = splitAlternate(head, &secondHead);

  cout << "First list (odd positions): ";
  printList(head);

  cout << "Second list (even positions): ";
  printList(secondHead);

  return 0;
}
