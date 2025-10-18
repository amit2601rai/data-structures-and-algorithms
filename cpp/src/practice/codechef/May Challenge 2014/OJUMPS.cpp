#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    long long k;
    cin>>k;
    if((k+5)%6 == 0 || (k+3)%6 == 0 || k%6 == 0)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
return 0;
}
