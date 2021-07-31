int deepestOddLeaf(node root,int level){
    static int maxOddLevel = -1;
    if(!root)return -1;
    if(root->left == NULL && root->right == NULL){
        if(level%2 != 0){
            maxOddLevel = max(maxOddLevel,level);
            return maxOddLevel;
        }
    }
    return max(deepestOddLeaf(root->left,level+1),deepestOddLeaf(root->right,level+1));
}
