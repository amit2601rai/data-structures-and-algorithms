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

ll mulmod(ll a, ll b, ll c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

ll power(ll a, ll b, ll m){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x = mulmod(x,y,m);//x=(x*y)%m
        }
        y = mulmod(y,y,m);//y=(y*y)%m
        b /= 2;
    }
    return x%m;
}

int main(){
    int k;
    cin >> k;
    ll n = power(2, k, LLONG_MAX);
    ll ans = mulmod(6, power(4, n-2, mod), mod);
    cout << ans << endl;
    return 0;
}
