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
        int n, k;
        cin >> n >> k;
        vi nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n-2*k; i++) ans += nums[i];
        for (int i = n-2*k; i < n-k; i++) {
            ans += (nums[i]/nums[i+k]);
        }
        cout << ans << "\n";
    }
    return 0;
}
