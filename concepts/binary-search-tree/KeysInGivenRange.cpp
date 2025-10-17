void keysinrange(struct BtreeNode *root,int k1,int k2){
	if(!root)return ;
	if(root->data<k1)keysinrange(root->right,k1,k2);
	else if(root->data>k2)keysinrange(root->left,k1,k2);
	else if(root->data>=k1 && root->data<=k2){
		cout<<root->data<<" ";
		keysinrange(root->left,k1,k2);
		keysinrange(root->right,k1,k2);
	}
}
