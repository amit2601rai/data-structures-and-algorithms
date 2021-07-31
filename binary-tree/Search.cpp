bool search(struct BtreeNode* root,int key){
    if(!root)return false;
    else if(root->data==key)return true;
    else return (search(root->left,key)||search(root->right,key));
}


bool iterative_search(struct BtreeNode* root,int key){
    queue<struct BtreeNode*>Q;
    if(root==NULL)return false;
    Q.push(root);
    while(!Q.empty()){
        struct BtreeNode* temp;
        temp=Q.front();
        Q.pop();
        if(temp->data==key)return true;
        if(temp->left)Q.push(temp->left);
        if(temp->left)Q.push(temp->right);
    }
return false;
}
