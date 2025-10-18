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


int main(){
    string input;
    cin>>input;
    int n=0,e=0,ii=0,t=0;
    int len = input.size();
    FOR(i,0,len-1){
        if(input[i] == 'n')n++;
        else if(input[i] == 'e')e++;
        else if(input[i] == 'i')ii++;
        else if (input[i] == 't')t++;
    }
    n = (n-1)/2;
    e = e/3;
    cout<<min(n,min(e,min(t,ii)))<<endl;
return 0;
}
