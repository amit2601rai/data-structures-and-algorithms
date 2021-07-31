int max_element(struct BtreeNode* root){
    static int ans=INT_MIN;
    if(!root)return ans;
    int left_val=max_element(root->left);
    int right_val=max_element(root->right);
    ans=max(left_val,max(right_val,root->data));
    return ans;
}



int iterative_max_element(struct BtreeNode* root){
    int ans=INT_MIN;
    struct BtreeNode* temp;
    queue<struct BtreeNode*>Q;
    if(root==NULL)return ans;
    Q.push(root);
    while(!Q.empty()){
        temp=Q.front();
        Q.pop();
        ans=max(ans,temp->data);
        if(temp->left) Q.push(temp->left);
        if(temp->right) Q.push(temp->right);
    }
	return ans;
}
