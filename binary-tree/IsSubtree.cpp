/*This function checks whether S is subtree of T or not.*/
bool isSubtree(struct BtreeNode *S,struct BtreeNode *T){
	if(S==NULL)return true;
	if(T==NULL)return false;
	if(isidentical(S,T))return true;
	return (isSubtree(S,T->left)||isSubtree(S,T->right));
}
