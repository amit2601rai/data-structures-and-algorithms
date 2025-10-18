#include "LinkedListCommon.h"

int plen(struct node *head) {
  int len = 0;
  while (head) {
    len++;
    head = head->next;
  }
  return len;
}

bool palindrome(struct node *head) {
  struct node *p, *q;
  p = head;
  q = head;
  int length = plen(head);
  int l;
  if (length % 2 == 0)
    l = length / 2;
  else
    l = length / 2 + 1;
  for (int i = 1; i < l; i++) {
    p = p->next;
  }
  p->next = reverse(p->next);
  p = p->next;
  print(q);
  while (p) {
    if (q->data != p->data) return false;
    q = q->next;
    p = p->next;
  }
  return true;
}
