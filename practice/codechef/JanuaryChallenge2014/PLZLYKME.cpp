#include<iostream>

using namespace std;

bool power(long L,long D,long S,long C){
    long long x=S,y=C+1;
    D--;
    while(D > 0){
        if(D%2 == 1){
            x=x*y;
            if(x >= L)
               return true;
        }
        y = y*y;
        if(y >= L)
           return true;
        D /= 2;
    }
    if(x >= L)
        return true;
    return false;
}



int main(){
    int T;
    cin>>T;
    while(T--){
        long long L,S,D,C;
        cin>>L>>D>>S>>C;
        if(power(L,D,S,C))
            cout<<"ALIVE AND KICKING"<<endl;
        else
            cout<<"DEAD AND ROTTING"<<endl;
    }
return 0;
}
