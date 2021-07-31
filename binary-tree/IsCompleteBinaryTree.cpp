bool isCompleteBT(node root){
    queue<node>Q;
    Q.push(root);
    bool flag = false;
    while(!Q.empty()){
        node tmp = Q.top();
        Q.pop();
        if(tmp && flag) return false;
        if(!tmp) flag = true;
        if(tmp) Q.push(tmp->left);
        if(tmp) Q.push(tmp->right);
    }
return true;
}
