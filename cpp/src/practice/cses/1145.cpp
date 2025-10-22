#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<int> dp(n, -1);

  dp[0] = v[0];
  int max_len = 1;
  for (int i = 1; i < n; i++) {
    // lower_bound : gives len bucket above
    //[start, end)
    auto start = dp.begin();
    auto end = dp.begin() + max_len;
    auto it = lower_bound(start, end, v[i]);
    if (it == end) {
      dp[max_len++] = v[i];
    } else {
      *it = min(*it, v[i]);
    }
  }

  cout << max_len << endl;

  return 0;
}