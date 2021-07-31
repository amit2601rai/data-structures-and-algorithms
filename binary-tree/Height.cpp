int height(struct BtreeNode* root){
	if(root==NULL || (root->left==NULL&&root->right==NULL)) return 0; //tree with one node (or no node) has height zero
	else return(max(height(root->left),height(root->right))+1);
}
