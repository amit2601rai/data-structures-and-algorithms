//Recursive
void rPostOrder(node root){
    if(root){
        rPostOrder(root->left);
        rPostOrder(root->right);
        print(root->data);
    }
}

//Iterative-I
void iPostOrder(node root){
    if(!root)return;
    stack<node>s;
    do{
        while(root){
            s.push(root);
            root = root->left;
        }
        if(!s.empty() && s.top()->right == NULL){
            root = s.top();
            s.pop();
            print(root->data);
            while(!s.empty() && s.top()->right == root){
                root = s.top();
                print(root->data);
                s.pop();
            }
        }
        if(!s.empty())
            root = s.top()->right;
    }while(!s.empty());
}

//Iterative-II
void iPostOrder2(node root){
	stack<node> child;
	stack<node> par;
	if(!root)return ;
	child.push(root);
	while(!child.empty()){
		node temp=child.top();
		child.pop();
		par.push(temp);
		if(temp->left)
			child.push(temp->left);
		if(temp->right)
			child.push(temp->right);
	}
	while(!par.empty()){
		print(par.top()->data);
		par.pop();
	}
}


void postorder(node root){
    cout<<"Recursive:"<<endl;
    rPostOrder(root);
    cout<<endl;
    cout<<"Iterative-I:"<<endl;
    iPostOrder(root);
    cout<<endl;
    cout<<"Iterative-II:"<<endl;
    iPostOrder2(root);
}
