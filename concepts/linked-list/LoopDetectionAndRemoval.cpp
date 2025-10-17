//Not Tested
Node loopDetect(Node head){
	Node fast,slow;
	slow=fast=head;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)break;
	}
return slow;
}

void removeLoop(Node head, Node tmp){
    while(head != tmp){
        head = head->next;
        tmp = tmp->next;
    }
    while(tmp->next != head) tmp = tmp->next;
    tmp->next = NULL;
}


Node loopDetectionAndRemoval(Node head){
    Node tmp = loopDetect(head);
    removeLoop(head,tmp);
return head;
}
