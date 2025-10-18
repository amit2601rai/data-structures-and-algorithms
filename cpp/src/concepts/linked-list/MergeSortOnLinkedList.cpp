#include "LinkedListCommon.h"

Node splitInHalf(Node head) {
  Node slow = head;
  Node fast = head;
  Node prev = NULL;

  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  prev->next = NULL;  // Split the list
  return slow;        // Return head of second half
}

Node mergeTwoSortedLists(Node first, Node second) {
  if (first == NULL) return second;
  if (second == NULL) return first;

  if (first->data <= second->data) {
    first->next = mergeTwoSortedLists(first->next, second);
    return first;
  } else {
    second->next = mergeTwoSortedLists(first, second->next);
    return second;
  }
}

Node mergeSort(Node head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node secondHalf = splitInHalf(head);

  head = mergeSort(head);
  secondHalf = mergeSort(secondHalf);

  return mergeTwoSortedLists(head, secondHalf);
}

int main() {
  // Create an unsorted list: 4->2->1->3->5
  Node head = getNewNode(4);
  head->next = getNewNode(2);
  head->next->next = getNewNode(1);
  head->next->next->next = getNewNode(3);
  head->next->next->next->next = getNewNode(5);

  cout << "Original unsorted list: ";
  printList(head);

  head = mergeSort(head);

  cout << "Sorted list using merge sort: ";
  printList(head);

  return 0;
}
