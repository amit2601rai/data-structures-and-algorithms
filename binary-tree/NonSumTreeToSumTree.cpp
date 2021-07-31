void sumTreeCoversion(node root){
	int lvalue=0,rvalue=0;
	if(root==NULL || (root->left==NULL && root->right==NULL))return;
    sumTreeCoversion(root->left);
    sumTreeCoversion(root->right);
    if(root->left!=NULL)lvalue=root->left->data;
    if(root->right!=NULL)rvalue=root->right->data;
    root->data=lvalue+rvalue;
}
