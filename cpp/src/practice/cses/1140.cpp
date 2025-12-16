#include <algorithm>
#include <iostream>

using namespace std;

struct triplet {
  int s;
  int e;
  int p;

  bool operator<(const triplet& other) const {
    if (e != other.e) return e < other.e;
    return s < other.s;
  }
};

int find(vector<triplet>& v, int k, int low, int high) {
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (v[mid].e >= v[k].s)
      high = mid - 1;
    else
      low = mid;
  }

  if (v[high].e < v[k].s) return high;
  if (v[low].e < v[k].s) return low;

  return -1;
}

int main() {
  int n;
  cin >> n;

  vector<triplet> v;

  for (int i = 0; i < n; i++) {
    triplet t;
    cin >> t.s;
    cin >> t.e;
    cin >> t.p;
    v.push_back(t);
  }

  sort(v.begin(), v.end());

  vector<long long> dp(n);

  dp[0] = v[0].p;
  for (int i = 1; i < n; i++) {
    dp[i] = v[i].p;
    // binary search to find the index
    // v[i].s v[i].e v[i].p
    // upper first interval where v[i].s -1 >= v[k].e
    dp[i] = max(dp[i - 1], dp[i]);
    int idx = find(v, i, 0, i - 1);
    if (idx != -1) dp[i] = max(dp[i], v[i].p + dp[idx]);
  }
  cout << dp[n - 1] << endl;
  return 0;
}