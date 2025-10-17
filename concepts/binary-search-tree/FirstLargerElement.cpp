void firstLargerElement(node root, int key, int *ans){
    if(root == NULL) return;
    if(root->data > key){
        *ans = root->data;
         firstLargerElement(root->left, key, ans);
    }
    else firstLargerElement(root->right, key, ans);
}
