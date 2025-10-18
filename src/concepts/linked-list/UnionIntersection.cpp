#include "LinkedListCommon.h"

Node unionLists(Node head1, Node head2) {
    if (head1 == NULL && head2 == NULL) return NULL;
    else if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else if (head1->data == head2->data) {
        Node temp = getNewNode(head1->data);
        temp->next = unionLists(head1->next, head2->next);
        return temp;
    }
    else if (head1->data < head2->data) {
        Node temp = getNewNode(head1->data);
        temp->next = unionLists(head1->next, head2);
        return temp;
    }
    else {
        Node temp = getNewNode(head2->data);
        temp->next = unionLists(head1, head2->next);
        return temp;
    }
}

Node intersectionLists(Node head1, Node head2) {
    if (head1 == NULL || head2 == NULL) {
        return NULL;
    }
    else if (head1->data == head2->data) {
        Node temp = getNewNode(head1->data);
        temp->next = intersectionLists(head1->next, head2->next);
        return temp;
    }
    else if (head1->data < head2->data) {
        return intersectionLists(head1->next, head2);
    }
    else {
        return intersectionLists(head1, head2->next);
    }
}

int main() {
    // Create first sorted list: 1->3->5->7->9
    Node head1 = getNewNode(1);
    head1->next = getNewNode(3);
    head1->next->next = getNewNode(5);
    head1->next->next->next = getNewNode(7);
    head1->next->next->next->next = getNewNode(9);
    
    // Create second sorted list: 2->3->6->7->10
    Node head2 = getNewNode(2);
    head2->next = getNewNode(3);
    head2->next->next = getNewNode(6);
    head2->next->next->next = getNewNode(7);
    head2->next->next->next->next = getNewNode(10);
    
    cout << "List 1: ";
    printList(head1);
    
    cout << "List 2: ";
    printList(head2);
    
    Node unionResult = unionLists(head1, head2);
    cout << "Union: ";
    printList(unionResult);
    
    Node intersectionResult = intersectionLists(head1, head2);
    cout << "Intersection: ";
    printList(intersectionResult);
    
    return 0;
}
