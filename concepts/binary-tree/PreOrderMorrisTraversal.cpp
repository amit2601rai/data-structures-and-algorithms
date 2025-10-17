void morrisPreOrder(node root){
    node current,tmp;
    while(current){
        if(!current->left){
            print(current->data);
            current = current->right;
        }else{
            tmp = current->left;
            while(tmp->right != NULL && tmp->right != current){
                tmp = tmp->right;
            }
            if(tmp->right == NULL){
                tmp->right = current;
                print(current->data);
                current = current->left;
            }
            else if(tmp->right == current){
                tmp->right = NULL;
                current = current->right;
            }
        }
    }
}
