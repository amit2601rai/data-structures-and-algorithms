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


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
class FibonacciDiv2 {
public:
	int find(int);
};

int FibonacciDiv2::find(int N) {
    bool v[1000001];
    memset1d(v,1000000,false);
    int f0 = 0;
    int f1 = 1;
    v[0] = true;
    v[1] = true;
    while(true){
        int t = f0 + f1;
        if(t>1000000)break;
        v[t] = true;
        f0 = f1;
        f1 = t;
    }
    if(v[N])return 0;
    int left = N - 1;
    int right = N + 1;
    while(true){
        if(left < 1 || v[left])break;
        left--;
    }
    while(true){
        if(right > 1000000 || v[right])break;
        right++;
    }
    if(right > 1000000)return N-left;
    else if(left < 1)return right-N;
    else return min(right-N,N-left);
}
