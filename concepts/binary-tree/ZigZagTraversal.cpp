void zigZag(struct BtreeNode *root){
    stack<struct BtreeNode*>P;
    stack<struct BtreeNode*>Q;
    P.push(root);
    while(!P.empty() || !Q.empty()){
        struct BtreeNode *tmp;
        while(!P.empty()){
            tmp = P.top();
            cout<<tmp->data<<" ";
            P.pop();
            if(tmp->right)Q.push(tmp->right);
            if(tmp->left)Q.push(tmp->left);
        }
        cout<<endl;
        while(!Q.empty()){
            tmp = Q.top();
            cout<<tmp->data<<" ";
            Q.pop();
            if(tmp->left)P.push(tmp->left);
            if(tmp->right)P.push(tmp->right);
        }
        cout<<endl;
    }
}
