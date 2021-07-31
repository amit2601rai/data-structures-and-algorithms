int count_nodes(struct BtreeNode* root){
		if(root==NULL)return 0;
		return 1+count_nodes(root->left)+count_nodes(root->right);
}

