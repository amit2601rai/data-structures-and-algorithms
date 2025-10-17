bool isidentical(struct BtreeNode *root1,struct BtreeNode *root2){
	if(root1==NULL && root2==NULL)return true;
	if(root1==NULL || root2==NULL)return false;
	return ((root1->data==root2->data)&&isidentical(root1->left,root2->left)&&isidentical(root2->right,root2->right));
}
