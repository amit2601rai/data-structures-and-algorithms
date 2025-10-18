#include "LinkedListCommon.h"

Node sortedInsertInCircularList(Node head, int x) {
    Node newNode = getNewNode(x);
    
    // If list is empty
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself
        return newNode;
    }
    
    Node current = head;
    Node prev = NULL;
    
    // Find the last node (which points to head)
    while (current->next != head) {
        current = current->next;
    }
    
    // If x should be inserted before head
    if (x <= head->data) {
        newNode->next = head;
        current->next = newNode;
        return newNode;  // New node becomes head
    }
    
    // If x should be inserted after last node
    if (x >= current->data) {
        current->next = newNode;
        newNode->next = head;
        return head;
    }
    
    // Find insertion position in between
    current = head;
    while (current->next != head && current->next->data < x) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

void printCircularList(Node head) {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    
    Node current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    Node head = NULL;
    
    // Insert elements in sorted order
    head = sortedInsertInCircularList(head, 3);
    head = sortedInsertInCircularList(head, 1);
    head = sortedInsertInCircularList(head, 5);
    head = sortedInsertInCircularList(head, 2);
    head = sortedInsertInCircularList(head, 4);
    
    cout << "Sorted circular linked list: ";
    printCircularList(head);
    
    return 0;
}
