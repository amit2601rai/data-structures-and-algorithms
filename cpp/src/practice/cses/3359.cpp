#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//TODO - order(i,j) based optimization is not needed
void solve(int n, vector<string> v) {
  vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, make_pair(0, 0)));
  for (int j = n-2; j >=0; j--) dp[n-1][j] = make_pair(n-1, j + 1);
  for (int i = n-2; i >= 0; i--) dp[i][n-1] = make_pair(i + 1, n-1);

  for (int i = n-2; i >= 0; i--) {
    for (int j = n-2; j >= 0; j--) {
      if (v[i+1][j] < v[i][j+1])
        dp[i][j] = make_pair(i + 1, j);
      else
        dp[i][j] = make_pair(i, j + 1);
    }
  }

  int x = 0, y = 0;
  vector<char> ans;
  while (true) {
    if (x == n-1 && y == n-1) {ans.push_back(v[x][y]); break;}
    ans.push_back(v[x][y]);
    int tmp_x = dp[x][y].first;
    int tmp_y = dp[x][y].second;
    x = tmp_x;
    y = tmp_y;
  }
  for (size_t i = 0; i < ans.size(); i++) cout << ans[i];
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  solve(n, v);

  return 0;
}