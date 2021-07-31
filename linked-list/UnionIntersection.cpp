struct node * unionlist(struct node *head1,struct node *head2){
	if(head1==NULL && head2==NULL)return NULL;
	else if(head1==NULL)return head2;
	else if(head2==NULL)return head1;
	else if(head1->data==head2->data){
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=head1->data;
			temp->next=unionlist(head1->next,head2->next);
			return temp;
	}
	else if(head1->data<head2->data){
			struct node *temp;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->data=head1->data;
			temp->next=unionlist(head1->next,head2);
			return temp;
	}
	else{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=head2->data;
		temp->next=unionlist(head1,head2->next);
		return temp;
	}
}

struct node *intersection(struct node *head1,struct node *head2){
	if(head1==NULL && head2==NULL){
		return NULL;
	}
	else if(head1==NULL){
		return NULL;
	}
	else if(head2==NULL){
		return NULL;
	}
	else if(head1->data==head2->data){
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=head1->data;
		temp->next=intersection(head1->next,head2->next);
		return temp;
	}
	else if(head1->data<head2->data){
		return intersection(head1->next,head2);
	}
	else return intersection(head1,head2->next);
}
