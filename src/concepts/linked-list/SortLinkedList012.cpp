#include "LinkedListCommon.h"

Node sortList012(Node head) {
  if (head == NULL) return NULL;

  // Create separate lists for 0s, 1s, and 2s
  Node zeroHead = NULL, zeroTail = NULL;
  Node oneHead = NULL, oneTail = NULL;
  Node twoHead = NULL, twoTail = NULL;

  Node current = head;

  // Traverse the original list and distribute nodes
  while (current != NULL) {
    Node next = current->next;
    current->next = NULL;

    if (current->data == 0) {
      if (zeroHead == NULL) {
        zeroHead = zeroTail = current;
      } else {
        zeroTail->next = current;
        zeroTail = current;
      }
    } else if (current->data == 1) {
      if (oneHead == NULL) {
        oneHead = oneTail = current;
      } else {
        oneTail->next = current;
        oneTail = current;
      }
    } else {  // data == 2
      if (twoHead == NULL) {
        twoHead = twoTail = current;
      } else {
        twoTail->next = current;
        twoTail = current;
      }
    }
    current = next;
  }

  // Link the three lists together
  if (zeroTail) zeroTail->next = oneHead;
  if (oneTail) oneTail->next = twoHead;

  // Return the head of the new list
  if (zeroHead) return zeroHead;
  if (oneHead) return oneHead;
  return twoHead;
}

int main() {
  // Create a list with 0s, 1s, and 2s: 1->2->0->1->0->2->1->0
  Node head = getNewNode(1);
  head->next = getNewNode(2);
  head->next->next = getNewNode(0);
  head->next->next->next = getNewNode(1);
  head->next->next->next->next = getNewNode(0);
  head->next->next->next->next->next = getNewNode(2);
  head->next->next->next->next->next->next = getNewNode(1);
  head->next->next->next->next->next->next->next = getNewNode(0);

  cout << "Original list: ";
  printList(head);

  head = sortList012(head);

  cout << "Sorted list (0s, 1s, 2s): ";
  printList(head);

  return 0;
}
