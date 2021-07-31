void deepestLeftLeaf(node root,int level,bool isLeft,node &result){
    static int max_level = -1;
    if(!root)return;
    if(isLeft && root->left == NULL && root->right == NULL){
        if(max_level < level){
            max_level = level;
            result = root;
        }
        return;
    }
    deepestLeftLeaf(root->left,level+1,true,result);
    deepestLeftLeaf(root->right,level+1,false,result);
}
