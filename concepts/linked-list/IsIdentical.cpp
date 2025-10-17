bool identical(struct node* head1, struct node* head2){
	if(head1!=NULL && head2!=NULL)
		return identical(head1->next,head2->next)&&(head1->data==head2->data);
	else if(head1==NULL && head2==NULL)
		return true;
	return false;
}
