//Not Tested
map<int,Dnode>M;
struct lruCache{
    Dnode front;
    Dnode rear;
    int size = 0;
};


lruCache insertAtFront(lruCache myLRU,int pageNo){
    Dnode tmp = getNewDnode(pageNo);
    if(myLRU.front == NULL){
        myLRU.front = myLRU.rear = tmp;
        myLRU.size += 1;
        M[pageNo] = tmp;
    }else{
        tmp->next = myLRU.front;
        myLRU.front->prev = tmp;
        myLRU.front = tmp;
        myLRU.size += 1;
        M[pageNo] = tmp;
    }
    return myLRU;
}

lruCache removeFromEnd(lruCache myLRU){
    Dnode tmp = myLRU.rear;
    myLRU.rear = myLRU.rear->prev;
    myLRU.rear->next = NULL;
    free(tmp);
    return myLRU;
}

lruCache shiftToBegin(lruCache myLRU,int pageNo){
    Dnode tmp = M[pageNo];
    Dnode prev = tmp->prev;
    prev->next = tmp->next;
    tmp->next->prev =tmp->prev;
    tmp->next = myLRU.front;
    tmp->prev = NULL;
    myLRU.front = tmp;
    return myLRU;
}

Dnode refPage(lruCache myLRU,int pageNo,int frameSize){
    if(M[pageNo] == 0){
        if(myLRU.size < frameSize){
            //simply insert at front
            myLRU = insertAtFront(myLRU,pageNo);
        }else{
            //remove from end
            myLRU = removeFromEnd(myLRU);
            //insert at front
            myLRU = insertAtFront(myLRU,pageNo);

        }
    }else{
        //shift to the beginning
        myLRU = shiftToBegin(myLRU,pageNo);
    }
    return myLRU;
}


void LRU(int frameSize){
    lruCache myLRU;
}
