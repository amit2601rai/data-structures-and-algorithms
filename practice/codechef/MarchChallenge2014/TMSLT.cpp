/*Author:Amit(IIIT-H)*/
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
        ll n,a,b,c,d,prev;
        cin>>n>>a>>b>>c>>d;
        int* des = new int[1000000];
        memset1d(des,0,999999);
        prev=d;
        des[prev]++;
        FOR(i,1,n-1){
            ll x = a*prev*prev;
            ll y = b*prev;
            ll z = (x+y+c)%1000000;
            prev = z;
            des[prev]++;
        }
        int k = 999999;
        int flag = 0;
        ll first = 0,second = 0;
        for(int z=k;z>=0;z--){
            if(des[z]>0){
                if(des[z]%2 == 0){
                        first = first + (des[z]/2)*z;
                        second = second + (des[z]/2)*z;
                }else{
                    if(flag == 0){
                            first = first + (des[z]/2)*z + z;
                            second = second + (des[z]/2)*z;
                            flag = 1;
                    }else{
                            first = first + (des[z]/2)*z;
                            second = second + (des[z]/2)*z + z;
                            flag = 0;
                    }
                }
            }
        }
        cout<<abs(first-second)<<endl;
    }
return 0;
}
