#include "BinaryTreeCommon.h"

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
        if(temp->right)Q.push(temp->right);  // Fixed: was temp->left
    }
return false;
}

int main() {
    node root = setupTree();
    int searchKey = 28;
    
    cout << "Searching for " << searchKey << " in the binary tree:" << endl;
    cout << "Recursive search: " << (search(root, searchKey) ? "Found" : "Not Found") << endl;
    cout << "Iterative search: " << (iterative_search(root, searchKey) ? "Found" : "Not Found") << endl;
    
    searchKey = 999;
    cout << "Searching for " << searchKey << " in the binary tree:" << endl;
    cout << "Recursive search: " << (search(root, searchKey) ? "Found" : "Not Found") << endl;
    cout << "Iterative search: " << (iterative_search(root, searchKey) ? "Found" : "Not Found") << endl;
    
    return 0;
}
