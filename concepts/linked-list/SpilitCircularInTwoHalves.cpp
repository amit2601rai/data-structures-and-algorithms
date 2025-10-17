Node spilitCLL(Node head){
    if(!head) return NULL;
    if(head->next == head) return head;
    Node slow,fast;
    slow = fast = head;
    while(fast != head && fast->next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = head;
    while(fast -> next != head) fast = fast->next;
    Node tmp = slow->next;
    slow->next = head;
    fast->next = tmp;
return tmp;
}
