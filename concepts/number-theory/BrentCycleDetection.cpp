#include<iostream>

using namespace std;

/*For sample we can take any hard-coded function*/
int f(int x){
    if(x == -1)return -1;
    int a[9] = {6,6,0,1,4,3,3,4,0};
    return a[x];
}

/*Return pair of first index of starting point Of cycle and length of cycle If exists Otherwise <-1,-1>*/
pair<int,int> CycleDetection(int x0){
    int power,lambda,hare,turtle,mu=0;
    power = lambda = 1;
    turtle = x0;
    hare = f(x0);
    while(true){
            if(hare == turtle && hare != -1){
                break;
            }
            if(power == lambda){
                turtle = hare;
                power *= 2;
                lambda = 0;
            }
            hare = f(hare);
            if(hare == -1)
                return make_pair(-1,1);
            lambda += 1;
    }
    turtle = hare = x0;
    for(int i=0;i<lambda;i++){
            hare = f(hare);
    }
    while(turtle != hare){
        mu++;
        hare = f(hare);
        turtle = f(turtle);
    }
    return make_pair(mu,lambda);

}

int main(){
    int x;
    cin>>x;
    pair<int,int>result = CycleDetection(x);
    cout<<result.first<<" "<<result.second<<endl;
return 0;
}
