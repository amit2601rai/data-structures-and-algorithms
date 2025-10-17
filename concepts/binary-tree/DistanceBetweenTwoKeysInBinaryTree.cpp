//Keys Should Be Distinct in the Binary Tree
node lca(node root,int p,int q){
    if(!root)return NULL;
    if(root->data == p || root->data == q)return root;
    node left = lca(root->left,p,q);
    node right = lca(root->right,p,q);
    if(left && right)return root;
    return left ? left:right;
}


int disOfLca(node root,node lca,int level){
    if(root == NULL || lca == NULL)return 0;
    if(root == lca)return level;
    return disOfLca(root->left,lca,level+1)+disOfLca(root->right,lca,level+1);
}

int disOfKeys(node root,int key,int level){
    if(!root)return 0;
    if(root->data == key)return level;
    return disOfKeys(root->left,key,level+1)+disOfKeys(root->right,key,level+1);

}

int distanceBetweenTwoKeys(node root,int a,int b){
    node lcaofab = lca(root,a,b);
    return disOfKeys(root,a,0)+disOfKeys(root,b,0)-2*disOfLca(root,lcaofab,0);
}
