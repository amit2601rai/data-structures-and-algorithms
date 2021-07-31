bool isBST(struct node *root,int minval,int maxval){
	if(!root)return true;
	if(root->data<minval || root->data>maxval)return false;
	return (isBST(root->left,minval,root->data-1)&&isBST(root->right,root->data+1,maxval);
}
