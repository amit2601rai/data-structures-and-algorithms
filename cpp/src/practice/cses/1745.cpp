#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<vector<bool>> dp(n, vector<bool>(100005, false));
  dp[0][v[0]] = true;
  for (int i = 0; i < n; i++) dp[i][0] = true;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < 100005; j++) {
      dp[i][j] = dp[i-1][j] || ((j-v[i] >= 0) ? dp[i-1][j-v[i]] : false);
    }
  }
  vector<int> ans;
  for (int j = 1; j < 100005; j++) {
    if (dp[n-1][j]) ans.push_back(j);
  }
  cout << ans.size() << endl;
  for (int sum : ans) cout << sum << " ";
  cout << endl;
}