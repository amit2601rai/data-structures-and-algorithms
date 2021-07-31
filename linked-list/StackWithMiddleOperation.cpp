struct StackWithMiddle{
    Dnode top=NULL,middle=NULL;
    int size = 0;
};
typedef StackWithMiddle MStack;

Dnode getTop(MStack* s){
    return (s->size !=0 ? s->top : NULL);
}
Dnode getMiddle(MStack* s){
    return (s->size !=0 ? s->middle : NULL);
}
void pop(MStack* s){
    if(s->size == 0)return;
    Dnode tmp = s->top;
    s->top = s->top->next;
    tmp->next = NULL;
    free(tmp);
    s->size--;
    if(s->size%2 == 0)
        s->middle = s->middle->next;
}

void push(MStack* s,int x){
    Dnode tmp = getNewDnode(x);
    if(s->top == NULL){
        s->top = tmp;
        s->middle = tmp;
        s->size++;
        return;
    }
    tmp->next = s->top;
    s->top->prev = tmp;
    s->top = tmp;
    s->size++;
    if(s->size%2 != 0)
        s->middle = s->middle->prev;
}

void TestDriver(){
    MStack S;
    MStack* ptrS;
    ptrS = &S;
    push(ptrS,1);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    push(ptrS,2);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    push(ptrS,3);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    push(ptrS,4);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    push(ptrS,5);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    pop(ptrS);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    pop(ptrS);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    pop(ptrS);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    pop(ptrS);
    cout<<"Middle = "<<getMiddle(ptrS)->data<<endl;
    pop(ptrS);
   Dnode t = getMiddle(ptrS);
   if(t)cout<<"Middle = "<<t->data<<endl;
}
