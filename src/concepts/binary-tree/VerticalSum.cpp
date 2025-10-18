#include "BinaryTreeCommon.h"

map<int,int>Hash;

void verticalsum(struct BtreeNode* root,int column){
	if(root==NULL)return;
	verticalsum(root->left,column-1);
	Hash[column] += root->data;
	verticalsum(root->right,column+1);
}

void printhash(){
	map<int,int>::iterator it;
	for(it=Hash.begin();it!=Hash.end();it++)
		cout<<"Column "<<(*it).first<<": "<<(*it).second<<endl;
}

int main() {
    node root = setupTree();
    Hash.clear(); // Reset the global map
    
    cout << "Vertical sum of the binary tree:" << endl;
    verticalsum(root, 0);
    printhash();
    
    return 0;
}
