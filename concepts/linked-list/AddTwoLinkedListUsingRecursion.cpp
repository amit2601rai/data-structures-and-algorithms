struct node* add_list_rec(struct node *head1,struct node *head2,int carry){
	int sum;
	struct node *result=(struct node*)malloc(sizeof(struct node));
	if(head1==NULL && head2==NULL){
		if(carry){
			result->data=carry;
			result->next=NULL;
			return result;
		}
		return NULL;
	}
	else if(head1==NULL){
		sum=head2->data+carry;
		carry=sum/10;
		result->data=sum%10;
		result->next=add_list_rec(head1,head2->next,carry);
	}
	else if(head2==NULL){
		sum=head1->data+carry;
		carry=sum/10;
		result->data=sum%10;
		result->next=add_list_rec(head1->next,head2,carry);
	}
	else{
		sum=head1->data+head2->data+carry;
		carry=sum/10;
		result->data=sum%10;
		result->next=add_list_rec(head1->next,head2->next,carry);
	}
	return result;
}
