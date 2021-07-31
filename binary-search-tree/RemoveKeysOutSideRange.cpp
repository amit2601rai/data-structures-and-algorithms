struct BtreeNode *removekeys(struct BtreeNode *root,int minval,int maxval){
	if(!root)return NULL;
	root->left=removekeys(root->left,minval,maxval);
	root->right=removekeys(root->right,minval,maxval);
	struct BtreeNode *child;
	if(root->data < minval){
		child=root->right;
		free(root);
		return child;
	}
	else if(root->data >maxval){
		child=root->left;
		free(root);
		return child;
	}
	else return root;
}
