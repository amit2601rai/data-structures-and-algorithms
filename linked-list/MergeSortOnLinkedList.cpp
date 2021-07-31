Node spilitInHalf(Node head){
    Node slow,fast;
    slow = fast = head;
    while(fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
return fast;
}

Node mergeList(Node p,Node q){
    Node temp = NULL;
    if(p == NULL && q == NULL)return NULL;
    if(p == NULL)return q;
    if(q == NULL)return p;
    if(p->data <= q->data){
        temp = p;
        temp->next = mergeList(p->next,q);
    }
    else{
        temp = q;
        temp->next = mergeList(p,q->next);
    }
  return temp;
}

Node mergeSort(Node head){
    if(head == NULL || head->next == NULL)
        return head;
    Node a = spilitInHalf(head);
    Node b = head;
    a = mergeSort(a);
    b = mergeSort(b);
return mergeList(a,b);
}
