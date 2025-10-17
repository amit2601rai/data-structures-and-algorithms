void printSinglyLinkedList(Node head){
    while(head){
        print(head->data);
        head = head->next;
    }
    print("\n");
}

void printCircularLinkedList(Node head){
    if(!head)return;
    Node tmp = head;
    do{
        print(tmp->data);
        tmp = tmp->next;
    }while(tmp != head);
    print("\n");
}

void printDoublyLinkedList(Dnode head){
    while(head){
        print(head->data);
        head = head->next;
    }
    print("\n");
}
