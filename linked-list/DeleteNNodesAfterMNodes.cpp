Node deleteNAfterM(Node head,int m,int n){
    Node prev = head;
    Node cur,tmp;
    for(int i=1; i<m; i++){
        if(!prev)return head;
        prev = prev->next;
    }
    if(!prev)return head;
    cur = prev->next;
    for(int i=1; i<=n; i++){
        tmp = cur;
        if(!cur)return head;
        cur = cur->next;
        free(tmp);
    }
    prev->next = cur;
return head;
}
