void mirror(struct BtreeNode* root){
	if(root){
        mirror(root->left);
        mirror(root->right);
        struct BtreeNode *temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}


