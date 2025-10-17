#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef priority_queue<int, vi, greater<int> > minHeap;
typedef priority_queue<int> maxHeap;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define tr(c, val) for (const auto &val : c)
#define ispresent(c, val) if(c.find(val) != c.end())
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;


ll fact(ll n) {
    if (n == 0) return 1;
    return n*fact(n-1);
}

ll ncr(ll n, ll r) {
    return fact(n)/(fact(n-r)*fact(r));
}

int main(){
    ll n;
    cin >> n;
    cout << (ncr(n, n/2LL)*fact(n/2-1)*fact(n/2-1))/2LL << endl;
    return 0;
}
