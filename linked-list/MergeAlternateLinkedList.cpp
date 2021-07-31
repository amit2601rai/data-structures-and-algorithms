void mergeAtAlternatePos(Node head1,Node head2){
    Node p = head1,q = head2;
    Node tmp,tmp2;
    while(p && q){
        tmp = p->next;
        p->next = q;
        tmp2= q->next;
        q->next = tmp;
        p= tmp;
        q= tmp2;
    }
    head2 = q;
    printSinglyLinkedList(head1);
    printSinglyLinkedList(head2);
}
