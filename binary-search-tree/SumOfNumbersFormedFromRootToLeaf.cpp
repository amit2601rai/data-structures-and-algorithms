//Tree Should Contain numbers in 0-9 Range
int formNumber(int path[],int k){
    int z=1,num=0;
    for(int i=k-1;i>=0;i--){
        cout<<path[i]<<" ";
        num = num + path[i]*z;
        z *= 10;
    }
    cout<<endl;
return num;
}
int sumOfNumbersFormed(node root,int path[],int k){
    if(!root)return 0;
    if(root->left == NULL && root->right == NULL ){
        path[k++] = root->data;
        return formNumber(path,k);
    }
    path[k++] = root->data;
    return sumOfNumbersFormed(root->left,path,k)+sumOfNumbersFormed(root->right,path,k);
}
