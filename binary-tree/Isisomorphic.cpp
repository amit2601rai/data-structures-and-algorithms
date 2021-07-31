bool Isisomorphic(struct BtreeNode *root1,struct BtreeNode *root2){
	if(root1 == NULL && root2 == NULL) return true;
	if(root1 == NULL || root2 == NULL) return false;
	return ((Isisomorphic(root1->left,root2->left)&&Isisomorphic(root1->right,root2->right))||
			(Isoisomorphic(root1->right,root1->left)&&Isisomorphic(root1->left,root2->right)));
}
