#include "BinaryTreeCommon.h"

void reverseleveltraversal(struct BtreeNode* root){
	if(!root)return;
	queue<struct BtreeNode*>q;
	stack<struct BtreeNode*>s;
	struct BtreeNode *temp;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==NULL && q.empty()) continue;
        else if(temp==NULL){
            q.push(NULL);
            s.push(NULL);
        }
        else{
            if(temp->right)q.push(temp->right);
            if(temp->left)q.push(temp->left);
            s.push(temp);
        }
	}
	while(!s.empty()){
		temp=s.top();
		s.pop();
		if(!temp)cout<<endl;
		else cout<<temp->data<<" ";
	}
	cout<<endl;
}

int main() {
    node root = setupTree();
    cout << "Reverse level order traversal:" << endl;
    reverseleveltraversal(root);
    return 0;
}
