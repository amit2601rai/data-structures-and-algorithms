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

pair<int, int> getRange(int k) {
    int power = INT_MIN;
    for (int i = 1; i <= k; i++) {
        int val;
        cin >> val;
        power = max(power, val - i + 2);
    }
    return mp(power, power + k);
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vii v;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            v.pb(getRange(k));
        }
        sort(v.begin(), v.end());
        int ans = v[0].first;
        int num = v[0].second - v[0].first;
        for (int i = 1; i < v.size(); i++) {
            ans = max(ans, v[i].first - num);
            num += (v[i].second - v[i].first);
        }
        cout << ans << endl;
    }
    return 0;
}
