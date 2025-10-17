Node rotateLinkedList(Node head,int k){
    Node last = head,tmp;
    while(last->next != NULL)
        last = last->next;
    while(k--){
        tmp = head;
        head = head->next;
        last->next = tmp;
        tmp->next = NULL;
        last = last->next;
    }
    return head;
}
