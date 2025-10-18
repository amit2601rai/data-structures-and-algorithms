#include "LinkedListCommon.h"

bool cycledetect(struct node *head) {
  struct node *fast, *slow;
  slow = fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }
  return false;
}

Node createListWithLoop() {
  Node head = getNewNode(1);
  head->next = getNewNode(2);
  head->next->next = getNewNode(3);
  head->next->next->next = getNewNode(4);
  head->next->next->next->next = head->next;  // Create loop
  return head;
}

int main() {
  Node head = setupList();

  cout << "List without loop: ";
  bool hasLoop = cycledetect(head);
  cout << (hasLoop ? "Loop detected" : "No loop") << endl;

  Node loopList = createListWithLoop();
  cout << "List with loop: ";
  hasLoop = cycledetect(loopList);
  cout << (hasLoop ? "Loop detected" : "No loop") << endl;

  return 0;
}
