#include "LinkedListCommon.h"

Node merge(Node p, Node q) {
  Node temp = NULL;
  if (p == NULL && q == NULL) return NULL;
  if (p == NULL) return q;
  if (q == NULL) return p;
  if (p->data <= q->data) {
    temp = p;
    temp->next = merge(p->next, q);
  } else {
    temp = q;
    temp->next = merge(p, q->next);
  }
  return temp;
}

Node createSortedList(int arr[], int n) {
  Node head = NULL;
  for (int i = 0; i < n; i++) {
    if (head == NULL) {
      head = getNewNode(arr[i]);
    } else {
      Node temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = getNewNode(arr[i]);
    }
  }
  return head;
}

int main() {
  int arr1[] = {1, 3, 5, 7};
  int arr2[] = {2, 4, 6, 8};

  Node list1 = createSortedList(arr1, 4);
  Node list2 = createSortedList(arr2, 4);

  cout << "List 1: ";
  printList(list1);

  cout << "List 2: ";
  printList(list2);

  Node merged = merge(list1, list2);

  cout << "Merged List: ";
  printList(merged);

  return 0;
}
