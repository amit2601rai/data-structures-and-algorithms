#include "LinkedListCommon.h"

struct node *removeduplicatefromsorted(struct node *head) {
  struct node *p, *q;
  p = head;
  while (p) {
    q = p->next;
    while (q != NULL && p->data == q->data) {
      p->next = q->next;
      free(q);
      q = p->next;
    }
    p = p->next;
  }
  return head;
}

Node createSortedListWithDuplicates() {
  Node head = getNewNode(1);
  head->next = getNewNode(1);
  head->next->next = getNewNode(2);
  head->next->next->next = getNewNode(3);
  head->next->next->next->next = getNewNode(3);
  head->next->next->next->next->next = getNewNode(3);
  head->next->next->next->next->next->next = getNewNode(4);
  return head;
}

int main() {
  Node head = createSortedListWithDuplicates();

  cout << "Original sorted list with duplicates: ";
  printList(head);

  head = removeduplicatefromsorted(head);

  cout << "After removing duplicates: ";
  printList(head);

  return 0;
}
