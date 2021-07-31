bool cycledetect(struct node *head){
	struct node *fast,*slow;
	slow=fast=head;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast) return true;
	}
	return false;
}
