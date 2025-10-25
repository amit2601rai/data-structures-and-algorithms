#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
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
#define ispresent(c, val) if (c.find(val) != c.end())
#define setp(v, n) \
  cout << fixed;   \
  cout << setprecision(n) << v << endl;

int findel(vi v, int n) {
  int low = 0, high = n - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (mid % 2 == 0) {
      if (mid + 1 < n && v[mid] == v[mid + 1])
        low = mid + 2;
      else
        high = mid;
    } else {
      if (mid - 1 >= 0 && v[mid] == v[mid - 1])
        low = mid + 1;
      else
        high = mid;
    }
  }
  return v[low];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << findel(v, n) << endl;
  }
  return 0;
}
