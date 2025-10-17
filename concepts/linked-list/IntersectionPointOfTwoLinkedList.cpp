//Not Tested
int length(Node head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
return len;
}

Node intersectionOfTwoLinkedList(Node p,Node q){
    int lenP = length(p);
    int lenQ = length(q);
    int diff;
    if(lenP>lenQ){
        diff = lenP-lenQ;
        while(diff--){
            p = p->next;
        }
    }else{
        diff = lenQ-lenP;
        while(diff--){
            q = q->next;
        }
    }
    while(p & q){
        if(p == q)return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}
