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

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vi v(n+1), max_so_far(n+1, INT_MIN);
        vi right_next_max(n+1, n+1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            max_so_far[i] = max(v[i], max_so_far[i-1]); 
        }
       
        stack<int> st;
        for (int i = n; i >= 1; i--) {
            while (!st.empty() && v[st.top()] < v[i])st.pop();
            if (!st.empty()) right_next_max[i] = st.top();
            st.push(i);
        }

        while (q--) {
            int i, k;
            cin >> i >> k;
            if (k < i-1 || v[i] < max_so_far[i]) {
                cout << "0\n";
            } else {
                if (v[i] == n) {
                    cout << max(0, k - (i - 2 >= 0 ? i - 2 : 0)) << endl;
                } else {
                    cout << min(k-i+1, right_next_max[i]-i-1)+ ((i > 1) ? 1 : 0) << endl;
                } 
            }
        }
    }
    return 0;
}