#include "BinaryTreeCommon.h"

// Helper function to check if two trees are identical
bool isidentical(struct BtreeNode *root1,struct BtreeNode *root2){
	if(root1==NULL && root2==NULL)return true;
	if(root1==NULL || root2==NULL)return false;
	return ((root1->data==root2->data)&&isidentical(root1->left,root2->left)&&isidentical(root1->right,root2->right));
}

/*This function checks whether S is subtree of T or not.*/
bool isSubtree(struct BtreeNode *S,struct BtreeNode *T){
	if(S==NULL)return true;
	if(T==NULL)return false;
	if(isidentical(S,T))return true;
	return (isSubtree(S,T->left)||isSubtree(S,T->right));
}

int main() {
    node mainTree = setupTree();
    
    // Create a subtree for testing
    node subtree = getNewNode();
    subtree->data = 26;
    subtree->left = getNewNode();
    subtree->left->data = 27;
    subtree->right = getNewNode();
    subtree->right->data = 28;
    
    cout << "Is the created subtree present in main tree? " << (isSubtree(subtree, mainTree) ? "Yes" : "No") << endl;
    
    // Test with a tree that's not a subtree
    node nonSubtree = getNewNode();
    nonSubtree->data = 999;
    cout << "Is the non-subtree present in main tree? " << (isSubtree(nonSubtree, mainTree) ? "Yes" : "No") << endl;
    
    return 0;
}
