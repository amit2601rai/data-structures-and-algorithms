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
		cout<<(*it).first<<" "<<(*it).second<<endl;
}
