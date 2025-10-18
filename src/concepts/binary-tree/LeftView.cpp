#include "BinaryTreeCommon.h"

#define print(a) cout<<a<<" "

void leftView(node root,int level){
    if(root == NULL)return;
    static int max_level = -1;
    if(level > max_level){
        print(root->data);
        max_level =  level;
    }
    leftView(root->left,level+1);
    leftView(root->right,level+1);
}

int main() {
    node root = setupTree();
    cout << "Left view of the binary tree: ";
    leftView(root, 0);
    cout << endl;
    return 0;
}
