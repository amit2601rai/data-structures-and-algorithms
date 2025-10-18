#include "LinkedListCommon.h"

// Floyd's Cycle Detection Algorithm
Node detectLoop(Node head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  Node slow = head;
  Node fast = head;

  // Move slow one step and fast two steps
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    // Loop detected
    if (slow == fast) {
      return slow;
    }
  }

  return NULL;  // No loop
}

void removeLoop(Node head, Node loopNode) {
  Node ptr1 = head;
  Node ptr2 = loopNode;

  // Find the start of the loop
  while (ptr1->next != ptr2->next) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  // Remove the loop by setting next of ptr2 to NULL
  ptr2->next = NULL;
}

bool hasLoop(Node head) { return detectLoop(head) != NULL; }

Node loopDetectionAndRemoval(Node head) {
  Node loopNode = detectLoop(head);

  if (loopNode != NULL) {
    cout << "Loop detected! Removing loop..." << endl;
    removeLoop(head, loopNode);
    cout << "Loop removed successfully." << endl;
  } else {
    cout << "No loop detected." << endl;
  }

  return head;
}

void printListWithLimit(Node head, int limit = 20) {
  Node current = head;
  int count = 0;

  while (current && count < limit) {
    cout << current->data << " ";
    current = current->next;
    count++;
  }

  if (current) {
    cout << "... (truncated after " << limit << " nodes)";
  }
  cout << endl;
}

int main() {
  // Create a linked list: 1->2->3->4->5
  Node head = getNewNode(1);
  head->next = getNewNode(2);
  head->next->next = getNewNode(3);
  head->next->next->next = getNewNode(4);
  head->next->next->next->next = getNewNode(5);

  cout << "Original list: ";
  printList(head);

  cout << "Checking for loop: " << (hasLoop(head) ? "Loop found" : "No loop") << endl;

  // Create a loop: 5 -> 3 (pointing back to node with value 3)
  head->next->next->next->next->next = head->next->next;
  cout << "\nCreated a loop: 5 points back to 3" << endl;

  cout << "List with loop (limited print): ";
  printListWithLimit(head, 10);

  cout << "Checking for loop: " << (hasLoop(head) ? "Loop found" : "No loop") << endl;

  // Remove the loop
  head = loopDetectionAndRemoval(head);

  cout << "\nAfter loop removal: ";
  printList(head);

  cout << "Checking for loop: " << (hasLoop(head) ? "Loop found" : "No loop") << endl;

  return 0;
}
