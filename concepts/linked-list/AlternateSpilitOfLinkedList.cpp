Node spilitAlternate(Node head){
    Node prev,cur;
    Node secondHead,secondHeadLast;
    secondHead = NULL;
    prev = head;
    cur = prev->next;
    while(cur){
        prev->next = cur->next;
        prev = prev->next;
        cur->next = NULL;
        if(secondHead == NULL){
            secondHeadLast = secondHead = cur;
        }
        else{
            secondHeadLast->next = cur;
            secondHeadLast = secondHeadLast->next;
        }
        cur = (prev != NULL ? prev->next : NULL);
    }
    return secondHead;
}
