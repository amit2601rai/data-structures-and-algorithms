void leftView(node root,int level){
    if(root == NULL)return;
    static int max_level = -1;
    if(level > max_level){
        print(root->data);
        max_level =  level;
    }
    leftView(root->left,level+1);
    leftView(root->right,level+1);
}
