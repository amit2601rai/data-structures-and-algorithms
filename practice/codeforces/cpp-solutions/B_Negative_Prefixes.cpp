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
        int n;
        cin >> n;
        vi nums(n), locked(n), unlocked;
        for (int i = 0; i < n; i++) cin >> nums[i];
        for (int i = 0; i < n; i++) cin >> locked[i];
        for (int i = 0; i < n; i++) {
            if (!locked[i]) unlocked.pb(nums[i]);
        }
        sort(unlocked.rbegin(), unlocked.rend());
        for (int i = 0, j = 0; i < n; i++) {
            if (locked[i])cout << nums[i] << " ";
            else cout << unlocked[j++] << " ";
        }
        cout << "\n";
    }
    return 0;
}
