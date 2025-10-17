struct BtreeNode{
			int data;
			struct BtreeNode *left;
			struct BtreeNode *right;
		};

typedef struct BtreeNode* node;

node getNewNode(){
    node tmp;
    tmp = (node)malloc(sizeof(struct BtreeNode));
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
