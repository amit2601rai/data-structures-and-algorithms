#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<string> &v, int i, int j, int n, int m) {
  if (v[i][j] == '.') {
    v[i][j] = '#';
    for (auto d : directions) {
      int ni = i + d.first;
      int nj = j + d.second;
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && v[ni][nj] == '.') {
        dfs(v, ni, nj, n, m);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.') {
        dfs(v, i, j, n, m);
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}