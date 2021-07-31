void printList(node head) {
    node current = head;
    do{
        cout<<current->data<<" ";
        current = current->right;
    }while(current != head);
    cout<<endl;
}

//Append two circular doubly linked list
node append(node x, node y){
    if(x == NULL) return y;
    if(y == NULL) return x;
    node xlast,ylast;
    xlast = x->left;
    ylast = y->left;
    xlast->right = y;
    y->left = xlast;
    x->left = ylast;
    ylast->right = x;
return x;
}

node treetoList(node root){
    node leftList,rightList,finalList;
    if(!root)return root;
    leftList = treetoList(root->left);
    rightList = treetoList(root->right);
    root->left = root;
    root->right = root;
    finalList = append(leftList,root);
    finalList = append(finalList,rightList);
return finalList;
}
