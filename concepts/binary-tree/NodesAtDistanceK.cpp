void nodesatkdis(struct BtreeNode *root,int k){
	if(!root)return;
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	nodesatkdis(root->left,k-1);
	nodesatkdis(root->right,k-1);
}
