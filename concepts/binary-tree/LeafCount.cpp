int count_leaf(struct BtreeNode* root){
    if(!root) return 0;
	else if(root->left==NULL && root->right==NULL )return 1;
	else return count_leaf(root->left)+count_leaf(root->right);
}

