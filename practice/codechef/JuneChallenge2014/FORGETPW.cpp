//Amit Rai (IIIT-Hyderabad)
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define INF INT_MAX
#define MINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        char x,y;
        string input;
        map<char,char>M;
        cin>>n;
        while(n--){
            cin>>x>>y;
            M[x] = y;
        }
        cin>>input;
        int len = input.size();
        FOR(i,0,len-1){
            if(M.count(input[i])>0){
                input[i] =  M[input[i]];
            }
        }
        int l = 0, d=0, r = len-1;
        while(l < len && input[l] == '0')l++;
        while(d < len && input[d] != '.')d++;
        while(r >= 0 && input[r] == '0')r--;
        bool flag = false;
        FOR(i,l,d-1){
            cout<<input[i];
            flag = true;
        }
        if(d < r){
            flag = true;
            FOR(i,d,r){
                cout<<input[i];
           }
        }
        if(!flag)cout<<"0";
        cout<<endl;
    }
return 0;
}
