#include "BinaryTreeCommon.h"

/* The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants
     (where we allow a node to be a descendant of itself).
  */

/*Complexity: O(n^2) [Top Down Approach] */
int count(struct BtreeNode*root,struct BtreeNode* p,struct BtreeNode* q){
	if(!root)return 0;
	if(root==p||root==q)return 1+count(root->left,p,q)+count(root->right,p,q);
	else return count(root->left,p,q)+count(root->right,p,q);
}

struct BtreeNode* LCA(struct BtreeNode* root,struct BtreeNode* p,struct BtreeNode* q){
    if(!root||!p||!q)return NULL;
	if(root==p||root==q)return root;//if current node either match with any of (p/q) that would be the LCA
	int counter=count(root->left,p,q);
	if(counter==0)return LCA(root->right,p,q);
	else if(counter==1)return root;
	else if(counter==2)return LCA(root->left,p,q);
    return NULL; // Added return statement
}


/*Complexity: O(n) [Bottom Up Approach] */
struct BtreeNode* LCA_2(struct BtreeNode* root,struct BtreeNode* p,struct BtreeNode* q){
    if(!root) return NULL;
    if(root == p || root == q) return root;
    struct BtreeNode* left=LCA_2(root->left,p,q);
    struct BtreeNode* right=LCA_2(root->right,p,q);
    if(left && right)return root;//p and q are on both sides
    return left ? left:right;//p and q are on either side
}


//Driver function for testing the Code
void driver_lca(struct BtreeNode* root){
	struct BtreeNode* p;
	struct BtreeNode* q;
	p=root;
	q=root;
	q=q->right;
	q=q->left;
	q=q->right;
	q=q->right;
	p=p->left;
	p=p->right;
	cout<<"Node p: "<<p->data<<endl;
	cout<<"Node q: "<<q->data<<endl;
    struct BtreeNode* lca1=LCA(root,p,q);
    struct BtreeNode* lca2=LCA_2(root,p,q);
	cout<<"LCA (method 1): "<<(lca1 ? lca1->data : -1)<<endl;
	cout<<"LCA (method 2): "<<(lca2 ? lca2->data : -1)<<endl;
}

int main() {
    node root = setupTree();
    cout << "Testing Lowest Common Ancestor (LCA):" << endl;
    driver_lca(root);
    return 0;
}
