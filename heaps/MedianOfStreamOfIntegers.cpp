#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

priority_queue<int> H1;//max Heap
priority_queue<int,vector<int>, greater<int> >H2;//min Heap

int getMedian(){
    if(H1.size() == H2.size())
        return (H1.top()+H2.top())/2;
    else if(H1.size() < H2.size())
        return H2.top();
    else return H1.top();
}

void insert(int x){
    if(H1.size() == 0 && H2.size() == 0){
            H1.push(x);
            return;
    }
    if(H1.top()>x)
        H1.push(x);
    else
        H2.push(x);
    int l = H1.size() - H2.size();
    int r = H2.size() - H1.size();
    if(l>1){
        H2.push(H1.top());
        H1.pop();
    }
    if(r>1){
        H1.push(H2.top());
        H2.pop();
    }
}

int main(){
    int x;
    while(true){
        cout<<"Number : ";
        cin>>x;
        insert(x);
        cout<<"\n\nMedian : ";
        cout<<getMedian()<<"\n\n";
    }
return 0;
}
