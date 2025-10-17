void printarray(int path[],int pathlen){
	for(int i=0;i<pathlen;i++)
		cout<<path[i]<<" ";
	cout<<endl;
}


void root_to_leaf(struct BtreeNode* root,int path[],int pathlen){
	if(root->left == NULL && root->right == NULL){
		path[pathlen]=root->data;
		pathlen++;
		printarray(path,pathlen);
	}
    else{
		path[pathlen]=root->data;
		pathlen++;
		root_to_leaf(root->left,path,pathlen);
		root_to_leaf(root->right,path,pathlen);
	}
}
