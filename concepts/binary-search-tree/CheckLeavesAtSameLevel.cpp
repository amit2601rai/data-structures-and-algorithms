bool isLeavesAtSameLevel(node root,int level){
    static int flag = -1;
    if(!root)return true;
    if(root->left == NULL && root->right == NULL){
        if(flag == -1){
            flag = level;
            return true;
        }
        if(flag != level)
            return false;
    }
    return isLeavesAtSameLevel(root->left,level+1)&&isLeavesAtSameLevel(root->right,level+1);
}
