Node sortedInsertInCircularList(Node head,int x){
    Node prev = NULL,cur = head,tmp;
    tmp = getNewNode(x);
    do{
        if(!cur){
            head = cur;
            break;
        }
        if(cur->data < x){
            prev = cur;
            cur = cur->next;
        }
        else{
            tmp->next = cur;
            prev->next = tmp;
            break;
        }
    }while(cur != head);
    return head;
}


Node insertInSortedCircularList(Node head, int x){
    Node prev = NULL, cur = head;
    Node tmp = getNewNode(x);
    if(!cur) {tmp->next = tmp; return tmp;}//empty list
    while(cur != head){
        if(cur->data < x){
            prev = cur;
            cur = cur->next;
        } else break;
    }
    if(!prev){
        tmp->next = cur;
        cur->next = tmp;
        head = tmp;
    } else{
        prev->next = tmp;
        tmp->next = cur;
    }
 return head;
}
