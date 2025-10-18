#include "LinkedListCommon.h"

// Function to reverse a linked list
Node reverseList(Node head) {
  Node prev = NULL;
  Node current = head;
  Node next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

Node addTwoLists(Node head1, Node head2) {
  head1 = reverseList(head1);
  head2 = reverseList(head2);

  int carry = 0;
  Node temp1, temp2, temp3;
  Node result, last;
  result = NULL;
  temp1 = head1;
  temp2 = head2;

  while (temp1 && temp2) {
    temp3 = getNewNode(0);
    int sum = temp1->data + temp2->data + carry;
    carry = sum / 10;

    if (result == NULL) {
      temp3->data = sum % 10;
      temp3->next = NULL;
      result = temp3;
      last = result;
    } else {
      temp3->data = sum % 10;
      temp3->next = NULL;
      last->next = temp3;
      last = last->next;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  while (temp1) {
    temp3 = getNewNode(0);
    temp3->next = NULL;
    int sum = temp1->data + carry;
    carry = sum / 10;
    temp3->data = sum % 10;
    last->next = temp3;
    last = last->next;
    temp1 = temp1->next;
  }

  while (temp2) {
    temp3 = getNewNode(0);
    temp3->next = NULL;
    int sum = temp2->data + carry;
    carry = sum / 10;
    temp3->data = sum % 10;
    last->next = temp3;
    last = last->next;
    temp2 = temp2->next;
  }

  if (carry) {
    temp3 = getNewNode(carry);
    temp3->next = NULL;
    last->next = temp3;
    last = last->next;
  }

  return reverseList(result);
}

int main() {
  // Create first number: 342 (represented as 2->4->3)
  Node head1 = getNewNode(2);
  head1->next = getNewNode(4);
  head1->next->next = getNewNode(3);

  // Create second number: 465 (represented as 5->6->4)
  Node head2 = getNewNode(5);
  head2->next = getNewNode(6);
  head2->next->next = getNewNode(4);

  cout << "First number: ";
  printList(head1);

  cout << "Second number: ";
  printList(head2);

  Node result = addTwoLists(head1, head2);

  cout << "Sum: ";
  printList(result);

  return 0;
}
