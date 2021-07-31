Dnode reverseDLL(Dnode head){
    Dnode prev = NULL,cur = NULL,next = NULL;
    prev = NULL;
    cur = head;
    next = (cur == NULL ? NULL : cur->next);
    while(cur){
        cur->next = prev;
        cur->prev = next;
        prev = cur;
        cur = next;
        next = (next == NULL ? NULL : next->next);
    }
return prev;
}
