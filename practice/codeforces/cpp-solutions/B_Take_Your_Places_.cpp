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


int swaps(vi v, int n) {
    int ans = 0;
    int p = 1, q = 2;
    while(p + 1 < n && q < n) {
        if (v[p-1] != v[p]) p++;
        else if (v[p-1] != v[q] && p < q) {
            ans += (q-p);
            swap(v[p], v[q]);
        }
        else q++;
    }    
    return ans;
}

int updateFirstElement(vi &v, int x, int n) {
    int swaps = 0;
    for (int i = 0; i < n; i++)  {
        if (v[i] == x) {
            swap(v[i], v[0]);
            swaps += i;
            break;
        }
    }
    return swaps;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, zeroes = 0, ones = 0;
        cin >> n;
        vi v(n);
        vi u(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i] %= 2;
            u[i] = v[i];
            if (v[i] == 0) zeroes++;
            else ones++;
        }

        if (abs(ones - zeroes) > 1) {
            cout << "-1\n";
        }
        else if (ones > zeroes) {
            // first element one
            cout << updateFirstElement(v, 1, n) + swaps(v, n) << endl;
        } else if(zeroes > ones) {
            // first element zero
            cout << updateFirstElement(v, 0, n) + swaps(v, n) << endl;
        } else {
            cout <<  min(updateFirstElement(u, 1, n)  + swaps(u, n), updateFirstElement(v, 0, n) + swaps(v, n))  << endl;
        }
    }
    return 0;
}
