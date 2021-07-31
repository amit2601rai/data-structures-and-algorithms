Node deleteAlternateNode(Node head){
    if(!head)return head;
    Node prev,cur;
    prev = head;
    cur = prev->next;
    while(cur){
        prev->next = cur->next;
        prev = prev->next;
        free(cur);
        cur = (prev != NULL) ? prev->next : NULL;
    }
return head;
}
