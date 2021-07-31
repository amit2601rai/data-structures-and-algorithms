bool has_k_nodes(struct node *root,int k){
	int count=0;
	while(root){
		count++;
		root=root->next;
	}
	if(count>=k)return true;
	else return false;
}

struct node* k_rev(struct node *root,int k){
	if(root==NULL)return NULL;
	if(!has_k_nodes(root,k))return root;
	struct node *prev,*cur,*next,*temp;
	temp=root;
	prev=NULL;
	cur=root;
	int count=k;
	while(count--){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	temp->next=k_rev(cur,k);
 return prev;
}
