#include "LinkedListCommon.h"

Dnode reverseDLL(Dnode head) {
    Dnode temp = NULL;
    Dnode current = head;
    
    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // Change head to the last node (which is now first)
    if (temp != NULL) {
        head = temp->prev;
    }
    
    return head;
}

int main() {
    Dnode head = setupDList();
    
    cout << "Original doubly linked list: ";
    printDList(head);
    
    head = reverseDLL(head);
    
    cout << "Reversed doubly linked list: ";
    printDList(head);
    
    return 0;
}
