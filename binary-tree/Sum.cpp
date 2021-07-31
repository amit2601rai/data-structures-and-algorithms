int sum_element(struct BtreeNode* root){
	if(root==NULL)return 0;
	return (root->data+sum_element(root->left)+sum_element(root->right));
}
