#include "LinkedListCommon.h"

Node mergeAtAlternatePos(Node head1, Node* head2) {
  if (head1 == NULL) return *head2;
  if (*head2 == NULL) return head1;

  Node p = head1;
  Node q = *head2;
  Node tmp, tmp2;

  while (p && q) {
    tmp = p->next;
    p->next = q;
    tmp2 = q->next;
    q->next = tmp;
    p = tmp;
    q = tmp2;
  }

  *head2 = q;  // Update head2 to remaining nodes
  return head1;
}

int main() {
  // Create first list: 1->2->3->4->5
  Node head1 = getNewNode(1);
  head1->next = getNewNode(2);
  head1->next->next = getNewNode(3);
  head1->next->next->next = getNewNode(4);
  head1->next->next->next->next = getNewNode(5);

  // Create second list: 10->20->30->40->50
  Node head2 = getNewNode(10);
  head2->next = getNewNode(20);
  head2->next->next = getNewNode(30);
  head2->next->next->next = getNewNode(40);
  head2->next->next->next->next = getNewNode(50);

  cout << "List 1 before merge: ";
  printList(head1);

  cout << "List 2 before merge: ";
  printList(head2);

  head1 = mergeAtAlternatePos(head1, &head2);

  cout << "List 1 after alternate merge: ";
  printList(head1);

  cout << "Remaining nodes from List 2: ";
  printList(head2);

  return 0;
}
