struct node *removeduplicatefromsorted(struct node *head){
	struct node *p,*q;
	p=head;
	while(p){
		q=p->next;
		while(q!=NULL && p->data==q->data){
			p->next=q->next;
			free(q);
			q=p->next;
		}
		p=p->next;
	}
return head;
}
