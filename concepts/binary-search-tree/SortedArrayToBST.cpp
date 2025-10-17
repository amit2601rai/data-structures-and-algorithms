node sortedArrayToBst(int a[],int low,int high){
    if(low>high)return NULL;
    int mid = (low+high)/2;
    node root = getNewNode();
    root->data = a[mid];
    root->left = sortedArrayToBst(a,low,mid-1);
    root->right = sortedArrayToBst(a,mid+1,high);
    return root;
}
