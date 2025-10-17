bool isChildrenSum(node root){
	if(!root)
		return true;
    int lvalue=0,rvalue=0;
	if(root->left)
        lvalue = root->left->data;
    if(root->right)
        rvalue = root->right->data;
    return (lvalue+rvalue == root->data && isChildrenSum(root->left) && isChildrenSum(root->right));
}
