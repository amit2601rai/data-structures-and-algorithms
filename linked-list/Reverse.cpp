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
