#include "LinkedListCommon.h"

Node insertAtBeginCLL(Node head, int x) {
    Node newNode = getNewNode(x);
    
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself
        return newNode;
    }
    
    // Find the last node
    Node last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    // Insert new node at beginning
    newNode->next = head;
    last->next = newNode;
    
    return newNode;  // New head
}

Node insertAtEndCLL(Node head, int x) {
    Node newNode = getNewNode(x);
    
    if (head == NULL) {
        newNode->next = newNode;  // Point to itself
        return newNode;
    }
    
    // Find the last node
    Node last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    // Insert new node at end
    newNode->next = head;
    last->next = newNode;
    
    return head;  // Head remains same
}

Node insertAtPositionCLL(Node head, int x, int pos) {
    if (pos <= 1) {
        return insertAtBeginCLL(head, x);
    }
    
    if (head == NULL) {
        Node newNode = getNewNode(x);
        newNode->next = newNode;
        return newNode;
    }
    
    Node newNode = getNewNode(x);
    Node current = head;
    
    // Traverse to position-1
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
        if (current == head) {
            // We've completed a full circle, insert at end
            return insertAtEndCLL(head, x);
        }
    }
    
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

void printCircularList(Node head) {
    if (head == NULL) {
        cout << "Empty circular list" << endl;
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
    
    // Test insertions
    head = insertAtBeginCLL(head, 10);
    cout << "After inserting 10 at beginning: ";
    printCircularList(head);
    
    head = insertAtEndCLL(head, 20);
    cout << "After inserting 20 at end: ";
    printCircularList(head);
    
    head = insertAtBeginCLL(head, 5);
    cout << "After inserting 5 at beginning: ";
    printCircularList(head);
    
    head = insertAtEndCLL(head, 30);
    cout << "After inserting 30 at end: ";
    printCircularList(head);
    
    head = insertAtPositionCLL(head, 15, 3);
    cout << "After inserting 15 at position 3: ";
    printCircularList(head);
    
    return 0;
}
