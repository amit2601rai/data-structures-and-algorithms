bool alt_has_k_nodes(struct node *root,int k){
	int c=0;
	while(root){
		c++;
		root=root->next;
	}
	if(c>=k)return true;
	else return false;
}

struct node* k_alter_rev(struct node *root,int k,bool flag){
	if(root==NULL)
		return NULL;
	if(!alt_has_k_nodes(root,k))
		return root;
	struct node *prev,*cur,*next,*temp;
	int c=k;
	if(flag){
        temp=root;
        prev=NULL;
        cur=root;
		while(c--){
			next=cur->next;
			cur->next=prev;
			prev=cur;
			cur=next;
		}
        temp->next=k_alter_rev(cur,k,false);
        return prev;
	}
	else{
		while(c--){
			prev=cur;
			cur=cur->next;
		}
        prev->next=k_alter_rev(cur,k,true);
        return temp;
	}
}
