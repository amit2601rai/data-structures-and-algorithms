bool haspathsum(struct BtreeNode* root,int sum){
	int subsum;
	if(root==NULL)return (sum==0);
    subsum=sum-root->data;
    return (haspathsum(root->left,subsum)||haspathsum(root->right,subsum));
}
