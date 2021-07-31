Node insertAtEndCLL(Node head,int x){
    Node tmp = getNewNode(x);
    if(head == NULL){
        tmp->next = tmp;
        head = tmp;
    }
    else{
        Node tmp2 = head;
        while(tmp2->next != head)
            tmp2 = tmp2->next;
        tmp->next = head;
        tmp2->next = tmp;
    }
    return head;
}
