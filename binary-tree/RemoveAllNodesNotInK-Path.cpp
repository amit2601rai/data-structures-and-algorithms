node removeNodes(node root,int K,int &sum){
    if(!root)return NULL;
    int lsum,rsum;
    lsum = sum + root->data;
    rsum = lsum;
    root->left = removeNodes(root->left,K,lsum);
    root->right = removeNodes(root->right,K,rsum);
    sum = max(lsum,rsum);
    if(sum<K){
        free(root);
        root = NULL;
    }
    return root;
}
