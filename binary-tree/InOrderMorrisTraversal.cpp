void morrisInOrder(node root){
    node current, tmp;
    while(current){
        if(current->left == NULL){
            print(current->data);
            current = current->right;
        }else{
            tmp = current->left;
            while(tmp->right != NULL && tmp->right != current)
                tmp = tmp->right;
            if(tmp->right == NULL){
                tmp->right = current;
                current = current->left
            }
            else if(tmp->right == current){
                print(current->data);
                tmp->right = NULL;
                current = current->right;
            }
        }
    }
}
