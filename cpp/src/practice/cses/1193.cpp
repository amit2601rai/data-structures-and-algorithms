#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool bfs(vector<string> &grid, int sx, int sy, int ex, int ey, int n, int m, vector<vector<pair<int, int>>> &parent) {
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<pair<int, int>> q;

  q.push(make_pair(sx, sy));
  visited[sx][sy] = true;
  parent[sx][sy] = make_pair(sx, sy);

  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    int x = curr.first;
    int y = curr.second;

    if (x == ex && y == ey) {
      return true;
    }

    for (auto d : directions) {
      int nx = x + d.first;
      int ny = y + d.second;

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
        visited[nx][ny] = true;
        parent[nx][ny] = make_pair(x, y);
        q.push(make_pair(nx, ny));
      }
    }
  }

  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
  int p = -1, q = -1, r = -1, s = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'A') {
        p = i, q = j;
      } else if (v[i][j] == 'B') {
        r = i, s = j;
      }
    }
  }

  if (bfs(v, p, q, r, s, n, m, parent)) {
    cout << "YES" << endl;

    // Reconstruct shortest path
    vector<char> path;
    int x = r, y = s;

    while (x != p || y != q) {
      int px = parent[x][y].first;
      int py = parent[x][y].second;
      char dir = (x > px) ? 'D' : (x < px) ? 'U' : (y > py) ? 'R' : 'L';
      path.push_back(dir);
      x = px;
      y = py;
    }

    cout << path.size() << endl;
    // Print path in reverse (from start to end)
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
      cout << *it;
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}