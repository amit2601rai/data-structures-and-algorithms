#include "LinkedListCommon.h"

Node pairwiseSwap(Node head) {
  Node prev, cur, tmp, thead;
  prev = head;
  cur = (prev == NULL ? NULL : prev->next);
  while (prev && cur) {
    if (prev == head)
      head = cur;
    else
      thead->next = cur;
    thead = prev;
    tmp = cur->next;
    cur->next = prev;
    prev->next = tmp;
    prev = prev->next;
    cur = (prev == NULL ? NULL : prev->next);
  }
  return head;
}

int main() {
  Node head = setupList();

  cout << "Original list: ";
  printList(head);

  head = pairwiseSwap(head);

  cout << "After pairwise swap: ";
  printList(head);

  return 0;
}
