Dnode insertAtBegin(Dnode head,int x){
    Dnode tmp = getNewDnode(x);
    if(head == NULL){
        head = tmp;
    }else{
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
    return head;
}

Dnode insertAtEnd(Dnode head,int x){
    Dnode tmp = getNewDnode(x);
    Dnode p = head;
    if(!p){
        head = tmp;
        return head;
    }
    while(p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->prev = p;
    return head;
}
