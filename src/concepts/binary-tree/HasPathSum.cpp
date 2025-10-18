#include "BinaryTreeCommon.h"

bool haspathsum(struct BtreeNode* root,int sum){
	if(root==NULL)return (sum==0);
    if(root->left==NULL && root->right==NULL) return (sum==root->data); // Leaf node check
    int subsum=sum-root->data;
    return (haspathsum(root->left,subsum)||haspathsum(root->right,subsum));
}

int main() {
    node root = setupTree();
    int targetSum = 48; // 21 + 12 + 15 (a possible path)
    cout << "Does tree have path with sum " << targetSum << "? " << (haspathsum(root, targetSum) ? "Yes" : "No") << endl;
    
    targetSum = 1000; // Unlikely sum
    cout << "Does tree have path with sum " << targetSum << "? " << (haspathsum(root, targetSum) ? "Yes" : "No") << endl;
    
    return 0;
}
