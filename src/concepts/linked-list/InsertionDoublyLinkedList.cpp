#include "LinkedListCommon.h"

Dnode insertAtBegin(Dnode head, int x) {
    Dnode newNode = getNewDnode(x);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Dnode insertAtEnd(Dnode head, int x) {
    Dnode newNode = getNewDnode(x);
    if (head == NULL) {
        return newNode;
    }
    
    Dnode current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
    return head;
}

Dnode insertAtPosition(Dnode head, int x, int pos) {
    if (pos <= 1) {
        return insertAtBegin(head, x);
    }
    
    Dnode newNode = getNewDnode(x);
    Dnode current = head;
    
    for (int i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        cout << "Position out of bounds" << endl;
        free(newNode);
        return head;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;
    return head;
}

int main() {
    Dnode head = NULL;
    
    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 5);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 15, 3);
    
    cout << "Doubly linked list after insertions: ";
    printDList(head);
    
    return 0;
}
