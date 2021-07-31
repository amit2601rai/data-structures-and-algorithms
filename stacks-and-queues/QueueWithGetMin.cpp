/*Amit Rai(IIIT Hyderabad)*/

#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;


class myQueue{

    private:

    queue<int> elements;
    queue<int> minElement;
    queue<int> maxElement;

    public:
        void push(int x){
            elements.push(x);
            if(minElement.empty()) minElement.push(x);
            else minElement.push(min(minElement.back(), x));
            if(maxElement.empty()) maxElement.push(x);
            else maxElement.push(max(maxElement.back(), x));
        }

        void pop(){
            if(!elements.empty())elements.pop();
        }

        int top(){
            if(!elements.empty()) return elements.front();
            else printf("Queue Is Empty !!!");
        }

        int getMin(){
            if(!minElement.empty()) return minElement.back();
            else printf("Queue Is Empty !!!");
        }

        int getMax(){
            if(!maxElement.empty()) return maxElement.back();
            else printf("Queue Is Empty !!!");
        }
};

int main(){
    //Testing Code
    myQueue q;
    q.push(9);
    q.push(8);
   // q.push(7);
    q.push(6);
    q.push(10);
    q.push(11);
    q.push(12);
    q.pop();
    q.pop();
    q.pop();
    cout<<q.getMax()<<endl;
    cout<<q.getMin()<<endl;
return 0;
}


