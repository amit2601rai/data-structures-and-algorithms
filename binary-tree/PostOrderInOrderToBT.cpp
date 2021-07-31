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

node treeFromPostOrderInOrder(int Post[],int In[],int &index,int low,int high){
    if(low>high)return NULL;
    int tmpIndex = searchKey(In,Post[index--],low,high);
    node root = getNewNode();
    root->data = In[tmpIndex];
    root->right = treeFromPostOrderInOrder(Post,In,index,tmpIndex+1,high);
    root->left = treeFromPostOrderInOrder(Post,In,index,low,tmpIndex-1);
    return root;
}


int main(){
    int n;
    cin>>n;
    int Post[n];
    int In[n];
    for(int i=0; i<n; i++)cin>>Post[i];
    for(int i=0; i<n; i++)cin>>In[i];
    int index = n-1;
    node root = treeFromPostOrderInOrder(Post,In,index,0,n-1);
    inorder(root);//for checking
return 0;
}
