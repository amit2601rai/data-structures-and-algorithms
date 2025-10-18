#include "LinkedListCommon.h"

void printSinglyLinkedList(Node head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printCircularLinkedList(Node head){
    if(!head)return;
    Node tmp = head;
    do{
        cout << tmp->data << " ";
        tmp = tmp->next;
    }while(tmp != head);
    cout << endl;
}

void printDoublyLinkedList(Dnode head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node slist = setupList();
    Dnode dlist = setupDList();
    
    cout << "Singly Linked List: ";
    printSinglyLinkedList(slist);
    
    cout << "Doubly Linked List: ";
    printDoublyLinkedList(dlist);
    
    return 0;
}
