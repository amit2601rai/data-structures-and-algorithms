node insert(node root,int x ){
	if(root==NULL){
	    node tmp = getNewNode();
	    tmp->data=x;
	    root=tmp;
	}
	else{
   		if(x <= root->data) root->left=insert(root->left,x);
		else root->right=insert(root->right,x);
       }
return root;
}
