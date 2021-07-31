int height_balanced(struct BtreeNode *root){
	if(root==NULL)
		return 1;
	else{
        int l=height(root->left);
        int h=height(root->right);
        return (abs(l-h)<=1 && height_balanced(root->left) && height_balanced(root->right));
    }
}
