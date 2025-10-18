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


void setToOne(int idx, vi &v) {
    for (int i = 0; i <= idx; i++) v[i] = 1;
}

void setToZero(int idx, vi &v) {
    for (int i = 0; i <= idx; i++) v[i] = 0;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vi v;
        int num = n;
        while (num != 0) {
            v.pb(num%10);
            num /= 10;
        }

        int idx = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == d) idx = i;
        }

        if (idx == -1) {
            cout << "0\n";
            continue;
        }

        if (d < 9) {
            v[idx]++;
            if (d != 0) setToZero(idx-1, v);
            else setToOne(idx-1, v);
        } else {
            setToZero(idx, v);
            idx++;
            int c = 1;
            while (idx < v.size()) {
                if (v[idx] + c == d) {
                    v[idx] = 0;
                    c = 1;
                } else {
                    v[idx] += c;
                    c = 0;
                }
                idx++;
            }
            if (c == 1) v.pb(1);
        }

        ll m = 0;
        int f = 1;

        for (int i = 0; i < v.size(); i++) {
            m += (v[i]*f);
            f *= 10;
        }

        cout << (m - n) << endl;

    }
    return 0;
}
