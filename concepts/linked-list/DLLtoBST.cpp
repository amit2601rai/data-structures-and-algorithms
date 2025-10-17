void inorder(Dnode head){
    if(head){
        inorder(head->prev);
        print(head->data);
        inorder(head->next);
    }
}

int countNodes(Dnode head){
    int nodeCount = 0;
    while(head){
        nodeCount++;
        head = head->next;
    }
return nodeCount;
}

Dnode dllToBSTUtil(Dnode *head_ref, int n){
    if(n<=0)return NULL;
    Dnode left;
    left = dllToBSTUtil(head_ref,n/2);
    Dnode root = *head_ref;
    root->prev = left;
    *head_ref = (*head_ref)->next;
    root->next = dllToBSTUtil(head_ref, n-n/2-1);
    return root;
}

node dllToBST(Dnode head){
    int n = countNodes(head);
    head = dllToBSTUtil(&head, n);
    inorder(head);
}
