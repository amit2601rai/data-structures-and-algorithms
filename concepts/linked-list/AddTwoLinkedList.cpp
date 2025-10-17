//Need Rewrite
struct node *add_lists(struct node *head1,struct node *head2){
	head1=reverse(head1);
	head2=reverse(head2);
	int carry=0;
	struct node *temp1,*temp2,*temp3;
	struct node *result,*last;
	result=NULL;
	temp1=head1;
	temp2=head2;
	while(temp1 && temp2){
        temp3=(struct node*)malloc(sizeof(struct node));
        int sum =temp1->data+temp2->data+carry;
        carry=sum/10;
		if(result==NULL){
			temp3->data=sum%10;
			temp3->next=NULL;
			result=temp3;
			last=result;
		}
		else{
			temp3->data=sum%10;
            temp3->next = NULL;
			last->next=temp3;
			last=last->next;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
    while(temp1){
        temp3=(struct node*)malloc(sizeof(struct node));
        temp3->next = NULL;
        int sum=temp1->data+carry;
        carry=sum/10;
        temp3->data=sum%10;
        last->next=temp3;
        last=last->next;
        temp1=temp1->next;
    }
    while(temp2){
       temp3=(struct node*)malloc(sizeof(struct node));
        temp3->next = NULL;
        int sum=temp2->data+carry;
        carry=sum/10;
        temp3->data=sum%10;
        last->next=temp3;
        last=last->next;
        temp2=temp2->next;
    }
	if(carry){
        temp3=(struct node*)malloc(sizeof(struct node));
        temp3->data=carry;
        temp3->next = NULL;
        last->next=temp3;
        last=last->next;
	}
    return reverse(result);
}
