Node sort01(Node head){
    Node prev,cur,head0,head0Tail;
    head0 = NULL;
    head0Tail=NULL;
    prev = NULL;
    cur = head;
    while(cur){
        if(cur->data == 0){
            if(head0 == NULL){
                head0 = cur;
                head0Tail = cur;
            }else{
                head0Tail->next = cur;
                head0Tail = head0Tail->next;
            }
            if(prev){
                prev->next = cur->next;
                cur = prev->next;
            }else{
                cur = cur->next;
                head = cur;
            }
        }
        prev = cur;
        cur = cur->next;
    }
    head0Tail->next = head;
    head = head0;
    return head;
}
