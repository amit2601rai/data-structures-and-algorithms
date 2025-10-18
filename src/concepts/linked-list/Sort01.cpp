#include "LinkedListCommon.h"

Node sort01(Node head) {
  Node prev, cur, head0, head0Tail;
  head0 = NULL;
  head0Tail = NULL;
  prev = NULL;
  cur = head;
  while (cur) {
    if (cur->data == 0) {
      if (head0 == NULL) {
        head0 = cur;
        head0Tail = cur;
      } else {
        head0Tail->next = cur;
        head0Tail = head0Tail->next;
      }
      if (prev) {
        prev->next = cur->next;
        cur = prev->next;
      } else {
        cur = cur->next;
        head = cur;
      }
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
  if (head0Tail) head0Tail->next = head;
  if (head0) head = head0;
  return head;
}

Node createBinaryList() {
  Node head = getNewNode(1);
  head->next = getNewNode(0);
  head->next->next = getNewNode(1);
  head->next->next->next = getNewNode(0);
  head->next->next->next->next = getNewNode(0);
  head->next->next->next->next->next = getNewNode(1);
  return head;
}

int main() {
  Node head = createBinaryList();

  cout << "Original list: ";
  printList(head);

  head = sort01(head);

  cout << "Sorted list (0s then 1s): ";
  printList(head);

  return 0;
}
