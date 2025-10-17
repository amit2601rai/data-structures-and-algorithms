int min_element(struct BtreeNode *root){
	if(!root)return INT_MAX;
	else return min(root->data,min(min_element(root->left),min_element(root->right)));
}
