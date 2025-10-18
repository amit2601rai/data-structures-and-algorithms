#include "LinkedListCommon.h"

// Using double pointer
void deleteAtBeg(Node* ptr) {
    Node temp;
    temp = *ptr;
    if (*ptr == NULL) {
        cout << "Empty list" << endl;
    } else {
        *ptr = temp->next;
        free(temp);
    }
}

void deleteAtEnd(Node* ptr) {
    Node temp, temp2;
    temp = *ptr;
    if (temp == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    if (temp->next == NULL) {
        *ptr = NULL;
        free(temp);
        return;
    }
    temp2 = temp->next;
    while (temp2->next != NULL) {
        temp = temp2;
        temp2 = temp2->next;
    }
    temp->next = NULL;
    free(temp2);
}

void deleteAtPos(Node* ptr, int pos) {
    if (*ptr == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    if (pos == 1) {
        deleteAtBeg(ptr);
        return;
    }
    
    Node temp1, temp2;
    temp1 = *ptr;
    temp2 = NULL;
    
    for (int i = 1; i < pos && temp1 != NULL; i++) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    
    if (temp1 == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    
    temp2->next = temp1->next;
    free(temp1);
}

// Using single pointer (returns new head)
Node deleteAtBegSingle(Node head) {
    if (head == NULL) return NULL;
    Node temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node deleteAtEndSingle(Node head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    Node p, q;
    p = head;
    q = head->next;
    
    while (q->next != NULL) {
        p = q;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

int main() {
    Node head = setupList();
    
    cout << "Original list: ";
    printList(head);
    
    // Test deletion at beginning
    deleteAtBeg(&head);
    cout << "After deleting first node: ";
    printList(head);
    
    // Test deletion at end
    deleteAtEnd(&head);
    cout << "After deleting last node: ";
    printList(head);
    
    // Test deletion at position
    deleteAtPos(&head, 2);
    cout << "After deleting node at position 2: ";
    printList(head);
    
    // Test single pointer versions
    head = deleteAtBegSingle(head);
    cout << "After deleting first node (single pointer): ";
    printList(head);
    
    head = deleteAtEndSingle(head);
    cout << "After deleting last node (single pointer): ";
    printList(head);
    
    return 0;
}
