#include "LinkedListCommon.h"

Node reverse(Node head){
    Node prev,cur,next;
    prev=NULL;
    cur=head;
    next = (cur == NULL ? NULL : cur->next);
    while(cur){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = (next == NULL ? NULL : next->next);
    }
return prev;
}

int main() {
    Node head = setupList();
    
    cout << "Original list: ";
    printList(head);
    
    head = reverse(head);
    
    cout << "Reversed list: ";
    printList(head);
    
    return 0;
}
