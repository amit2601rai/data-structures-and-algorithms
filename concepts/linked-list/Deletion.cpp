/** Using double pointer **/

void deleteatbeg(struct node **ptr)
	{
		struct node *temp;
		temp=*ptr;
		if(*ptr==NULL)
			cout<<"empty list"<<endl;
		else
		{
			temp=temp->next;
			*ptr=temp;
		}
	}

void deleteatend(struct node **ptr)
	{
		struct node *temp,*temp2;
		temp=*ptr;
		temp2=temp->next;
		while(temp2->next!=NULL)
			{
		  		temp=temp2;
				temp2=temp2->next;
			}
		temp->next=NULL;
	}

void deleteatpos(struct node **ptr,int pos)
	{
		pos--;
		struct node *temp1,*temp2;
		temp2=NULL;
		temp1=*ptr;
		if(pos==0)
		   deleteatbeg(ptr);
		else
		{
		 	while(pos--)
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			temp2->next=temp1->next;	
		}
	}


/*using single pointer*/

struct node *delatbeg(struct node *head){
		if(head==NULL)return NULL;
		struct node *temp=head;
		temp=NULL;
		return head->next;		
	}

void *delatend(struct node *head){
		if(head==NULL)return NULL;
		struct node *p,*q;
		p=head;
		q=head->next;
		if(q==NULL)return NULL;
		while(q->next!=NULL){
		p=q;
		q=q->next;
		}
		p->next=NULL;
	}
