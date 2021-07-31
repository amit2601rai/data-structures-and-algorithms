void nodesWithoutSiblings(node root){
    if(!root)return;
    if(root->left != NULL && root->right == NULL){
        cout<<root->left->data<<" ";
        nodesWithoutSiblings(root->left);
    }
    else if(root->left == NULL && root->right != NULL){
        cout<<root->right->data<<" ";
        nodesWithoutSiblings(root->right);
    }
    else{
        nodesWithoutSiblings(root->left);
        nodesWithoutSiblings(root->right);
    }
}
