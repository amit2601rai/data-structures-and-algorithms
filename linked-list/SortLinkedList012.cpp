struct node* sortlinkedlist012(struct node *head){	
	struct node *head1,*tail1,*head2,*tail2,*temp,*prev_temp;
	head1=tail1=head2=tail2=NULL;
	temp=head;
	prev_temp=NULL;
	while(temp){
		if(temp->data==1){
			//deleting from original
			if(temp==head){
				head=head->next;
				temp->next=NULL;
			}
			else {
				prev_temp->next=temp->next;
				temp->next=NULL;
			}
			//appending 1's list
			if(head1==NULL){
				head1=temp;
				tail1=temp;
			}
			else{
				tail1->next=temp;
				tail1=temp;
			}
		if(prev_temp)temp=prev_temp->next;
		else temp=head;
	}
	 else if(temp->data==2){
		 //deleting
			if(temp==head){
				head=head->next;
				temp->next=NULL;
			}
			else{
				prev_temp->next=temp->next;
				temp->next=NULL;
			}
			//appending 2's list
			if(head2==NULL){
				head2=temp;
				tail2=temp;
			}
			else{
				tail2->next=temp;
				tail2=temp;
			}
			if(prev_temp)temp=prev_temp->next;
			else temp=head;	
		}
		else{
				prev_temp=temp;
				temp=temp->next;
		}
	}
	temp=head;
	while(temp && temp->next!=NULL)
		temp=temp->next;
	if(temp)temp->next=head1;
	if(tail1)tail1->next=head2;
	if(head)return head;
	else if(head1) return head1;
	else return head2;
}
