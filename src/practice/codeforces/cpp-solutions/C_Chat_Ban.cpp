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


ll sum(ll k, ll m) {
    ll sum = 0;
    if (m <= k) {
        sum += ((m+1)*m)/2; 
    } else {
        ll l = m - k;
        sum += ((k+1)*k)/2; 
        sum += ((2*k-l-1)*l)/2;
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        ll k, x;
        cin >> k >> x;
        ll low = 1, high = 2*k - 1;
        while (high - low > 1) {
            ll mid = (low + high)/2;
            if (sum(k, mid) < x) low = mid + 1;
            else high = mid;
        }
        if (sum(k, low) < x) cout << high << endl;
        else cout << low << endl;
    }
    return 0;
}
