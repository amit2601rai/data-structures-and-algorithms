Node merge(Node p,Node q){
    Node temp = NULL;
    if(p==NULL && q==NULL)return NULL;
    if(p==NULL)return q;
    if(q==NULL)return p;
    if(p->data<=q->data){
        temp=p;
        temp->next=merge(p->next,q);
    }
    else{
        temp=q;
        temp->next=merge(p,q->next);
    }
  return temp;
}
