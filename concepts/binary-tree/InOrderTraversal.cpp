//Recursive
void rInOrder(node root){
    if(root){
        rInOrder(root->left);
        print(root->data);
        rInOrder(root->right);
    }
}

//Iterative-I
void iInOrder(node root){
    if(!root)return;
    stack<node>s;
    do{
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        print(root->data);
        root = root->right;
    }while(root || !s.empty());
}


void inorder(node root){
    cout<<"Recursive:"<<endl;
    rInOrder(root);
    cout<<endl;
    cout<<"Iterative-I:"<<endl;
    iInOrder(root);
    cout<<endl;
}
