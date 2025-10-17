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

int main(){
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v;
        for (ll i = 2; i*i <= n; i++) {
            int count = 0;
            while(n%i == 0) {
                n /= i;
                count++;
            }
            v.pb(mp(count, i));
        }
        if (n > 1) v.pb(mp(1,n));
        sort(v.rbegin(), v.rend());
        ll lastel = v[0].second;
        v[0].first--;
        for (int i =  1; i < v.size(); i++) {
            lastel *= pow(v[i].second, v[i].first);
        }
        cout << 1 + v[0].first << endl;
        while(v[0].first--) {
            cout << v[0].second<< " ";
        }
        cout << lastel << endl;
    }
    return 0;
}
