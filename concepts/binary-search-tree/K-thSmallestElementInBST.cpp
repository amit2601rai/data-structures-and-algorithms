int KthSmallestElement(node root,int &K){
    if(root){
        KthSmallestElement(root->left,K);
        K--;
        if(K == 0)return root->data;
        KthSmallestElement(root->right,K);
    }
}
