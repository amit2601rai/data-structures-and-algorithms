#include "Header.cpp"
#include "Node.cpp"
#include "InOrderTraversal.cpp"
#include "PreOrderTraversal.cpp"
#include "PostOrderTraversal.cpp"

int searchKey(int a[],int key,int low,int high){
    for(int i=low;i<=high;i++)
        if(key == a[i])
            return i;
}

node treeFromPreOrderInOrder(int Pre[],int In[],int &index,int low,int high){
    if(low>high)return NULL;
    int tmpIndex = searchKey(In,Pre[index++],low,high);
    node root = getNewNode();
    root->data = In[tmpIndex];
    root->left = treeFromPreOrderInOrder(Pre,In,index,low,tmpIndex-1);
    root->right = treeFromPreOrderInOrder(Pre,In,index,tmpIndex+1,high);
    return root;
}


int main(){
    int n;
    cin>>n;
    int Pre[n];
    int In[n];
    for(int i=0; i<n; i++)cin>>Pre[i];
    for(int i=0; i<n; i++)cin>>In[i];
    int index = 0;
    node root = treeFromPreOrderInOrder(Pre,In,index,0,n-1);
    inorder(root);//for checking
return 0;
}
