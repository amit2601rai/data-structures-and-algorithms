int countNodes2(Node head){
    int nodeCount = 0;
    while(head){
        nodeCount++;
        head = head->next;
    }
return nodeCount;
}

Dnode sortedLLToBSTUtil(Node *head_ref,int n){
    if(n<=0)return NULL;
    Dnode left = sortedLLToBSTUtil(head_ref,n/2);
    Dnode root = getNewDnode((*head_ref)->data);
    root->prev = left;
    (*head_ref) = (*head_ref)->next;
    root->next = sortedLLToBSTUtil(head_ref,n-n/2-1);
    return root;
}

//Version-2 Without Pointers
Dnode sortedLLToBSTUtil2(Node &head_ref,int n){
    if(n<=0)return NULL;
    Dnode left = sortedLLToBSTUtil(head_ref,n/2);
    Dnode root = getNewDnode(head_ref->data);
    root->prev = left;
    head_ref = head_ref->next;
    root->next = sortedLLToBSTUtil(head_ref,n-n/2-1);
    return root;
}

node sortedLLToBST(Node head){
    int n = countNodes2(head);
    Dnode rhead = sortedLLToBSTUtil(&head,n);
	Dnode rhead2 = sortedLLToBSTUtil2(head,n);
    inorder(rhead);
}
