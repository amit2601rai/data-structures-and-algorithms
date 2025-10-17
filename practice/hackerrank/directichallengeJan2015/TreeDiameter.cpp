/*
 * Complete the function below.
 */
#define present(c,x) ((c).find(x) != (c).end())
struct BtreeNode{
    int data;
    struct BtreeNode* left;
    struct BtreeNode* right;
};
typedef BtreeNode* node;
map<node,int>H;
map<node,int>D;

node getNewNode(){
    node tmp = (node)malloc(sizeof(struct BtreeNode));
    tmp->left = tmp->right = NULL;
    return tmp;
}

node insert(node root, int x){
    if(root==NULL){
        node tmp = getNewNode();
	    tmp->data=x;
	    root=tmp;
	}
	else{
   		if(x <= root->data) root->left=insert(root->left,x);
		else root->right=insert(root->right,x);
     }
return root;
}

int height(node root){
    if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;
	if(H[root]) return H[root];
    H[root] = max(height(root->left),height(root->right))+1;
	return H[root];
}

int diameter(node root){
    if(root==NULL||(root->left==NULL&&root->right==NULL))return 0;
	if(D[root]) return D[root];
	int leftD = diameter(root->left);
	int rightD = diameter(root->right);
	int leftH = height(root->left);
	int rightH = height(root->right);
	D[root] = max(leftD,max(rightD, leftH + rightH + (root->left != NULL) + (root->right != NULL))));
	return D[root];
}

void treeDiameter(vector < int > values) {
    node root = NULL;
    for(int i = 0; i<values.size(); i++){
        root = insert(root, values[i]);
    }
    int ans = diameter(root);
    ans++;
    cout<<ans<<endl;
}