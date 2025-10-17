/*Amit Rai(IIIT Hyderabad)*/
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

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)


class SRMCards {
public:
	int maxTurns(vector <int>);
};

int SRMCards::maxTurns(vector <int> cards) {
    sort(cards.begin(),cards.end());
    vector<int>v;
    for(int i=1; i<v.size(); i++){
        if(v[i] == v[i-1])counter++;
        else v.pb(counter),counter = 1;
    }
    v.pb(counter);
    int ans = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] % 2 == 0)ans += v[i]/2;
        else ans += (v[i]+1)/2;
    }
    return ans;
}
