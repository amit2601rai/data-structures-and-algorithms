void addAllGreaterElement(node root){
    static int value = 0;
    if(root){
        addAllGreaterElement(root->right);
        root->data += value;
        value = root->data;
        addAllGreaterElement(root->left);
    }
}
