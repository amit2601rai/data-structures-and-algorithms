#include "LinkedListCommon.h"

Node deleteAlternateNode(Node head) {
  if (!head) return head;
  Node prev, cur;
  prev = head;
  cur = prev->next;
  while (cur) {
    prev->next = cur->next;
    prev = prev->next;
    free(cur);
    cur = (prev != NULL) ? prev->next : NULL;
  }
  return head;
}

int main() {
  Node head = setupList();

  cout << "Original list: ";
  printList(head);

  head = deleteAlternateNode(head);

  cout << "After deleting alternate nodes: ";
  printList(head);

  return 0;
}
