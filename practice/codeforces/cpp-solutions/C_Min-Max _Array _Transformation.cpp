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


 vi a(200005), b(200005), dmin(200005), dmax(200005);

int get_index_equal_or_greater_element(int low, int high, int key) {
    while (high - low > 1) {
        int mid = (low + high)/2;
        if (b[mid] >= key) high = mid;
        else low = mid + 1;
    }
    if (b[low] >= key) return low;
    return high;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        int last = n-1;
        for (int i = n - 1; i >= 0; i--) {
            int k = get_index_equal_or_greater_element(0, last, a[i]);
            dmax[i] = max(b[k] - a[i], b[last] - a[i]);
            dmin[i] = min(b[k] - a[i], b[last] - a[i]);
            if (k == i) last = i - 1;
        }
        for (int i = 0; i < n; i++) printf("%d ",dmin[i]);
        printf("\n");
        for (int i = 0; i < n; i++) printf("%d ",dmax[i]);
        printf("\n");
    }
    return 0;
}