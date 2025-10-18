#include "LinkedListCommon.h"

Node addListRecursive(Node head1, Node head2, int carry) {
  int sum;
  Node result = getNewNode(0);

  if (head1 == NULL && head2 == NULL) {
    if (carry) {
      result->data = carry;
      result->next = NULL;
      return result;
    }
    free(result);
    return NULL;
  } else if (head1 == NULL) {
    sum = head2->data + carry;
    carry = sum / 10;
    result->data = sum % 10;
    result->next = addListRecursive(head1, head2->next, carry);
  } else if (head2 == NULL) {
    sum = head1->data + carry;
    carry = sum / 10;
    result->data = sum % 10;
    result->next = addListRecursive(head1->next, head2, carry);
  } else {
    sum = head1->data + head2->data + carry;
    carry = sum / 10;
    result->data = sum % 10;
    result->next = addListRecursive(head1->next, head2->next, carry);
  }
  return result;
}

int main() {
  // Create first number: 342 (represented as 3->4->2)
  Node head1 = getNewNode(3);
  head1->next = getNewNode(4);
  head1->next->next = getNewNode(2);

  // Create second number: 465 (represented as 4->6->5)
  Node head2 = getNewNode(4);
  head2->next = getNewNode(6);
  head2->next->next = getNewNode(5);

  cout << "First number (MSB first): ";
  printList(head1);

  cout << "Second number (MSB first): ";
  printList(head2);

  Node result = addListRecursive(head1, head2, 0);

  cout << "Sum (MSB first): ";
  printList(result);

  return 0;
}
