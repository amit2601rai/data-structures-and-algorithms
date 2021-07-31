struct node{
    int data;
    struct node *next;
};

struct dnode{
    int data;
    struct dnode *prev;
    struct dnode *next;
};

typedef struct node* Node;
typedef struct dnode* Dnode;

Node getNewNode(int data){
    Node tmp = (Node)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}
Dnode getNewDnode(int data){
    Dnode tmp = (Dnode)malloc(sizeof(struct dnode));
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}
