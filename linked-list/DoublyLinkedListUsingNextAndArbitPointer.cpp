//Not Tested

struct node{
    int data;
    struct node* next;
    struct node* arbit;
};
typedef struct node* node;
node getNewNode(int data){
    node tmp = (node)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = null;
    tmp->arbit = null;
    return tmp;
}

/**
Method 1: Using Extra Space
Time Complexity:  O(n)
Auxiliary Space:  O(n)**/

node clone(node headOriginal){
    map<node,node>M;
    node tmp,headOriginalTmp = headOriginal,headCopy = NULL,headCopyTmp;
    while(headOriginalTmp){
        tmp = headOringinalTmp->next;
        M[headOringinalTmp] = tmp;
        headOringinalTmp->next = getNewNode(headOringinalTmp->data);
        headOringinalTmp->next->arbit = headOringinalTmp;
        if(!headCopy){
            headCopy = headCopyTmp = headOringinalTmp->next;
        }
        headCopyTmp->next = headOringinalTmp->next;
        headOringinalTmp = tmp;
    }
    headCopyTmp = headCopy;
    while(headCopyTmp){
        headCopyTmp->arbit = headCopyTmp->arbit->arbit->next;
        headCopyTmp = headCopyTmp->next;
    }
    headOriginalTmp = headOriginal;
    while(headOriginalTmp){
        headOriginalTmp -> next = M[headOriginal];
        headOriginalTmp = headOriginalTmp -> next;
    }
    return headCopy;
}


/**
Method 2: Using Constant Space
Time Complexity: O(n)
Auxiliary Space: O(1) **/

node clone(node headOriginal){
}


