#include "BinaryTreeCommon.h"

void leveltraversal(struct BtreeNode *root){
	if(!root)return;
	queue<struct BtreeNode*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
	struct BtreeNode *temp;
	temp=q.front();
	q.pop();
	if(temp==NULL && q.empty()){
		cout<<endl;
	}
	else if(temp==NULL){
		cout<<endl;
		q.push(NULL);
	}
	else{
		if(temp->left)q.push(temp->left);
		if(temp->right)q.push(temp->right);
		cout<<temp->data<<" ";
	  }
	}
}

int main() {
    node root = setupTree();
    cout << "Level Order Traversal:" << endl;
    leveltraversal(root);
    return 0;
}
