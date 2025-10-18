#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool mycomp(string a,string b){
    string ab = a.append(b);
    string ba = b.append(a);
    return ab.compare(ba) > 0 ? true : false;
}

int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end(),mycomp);
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
    cout<<endl;
return 0;
}
