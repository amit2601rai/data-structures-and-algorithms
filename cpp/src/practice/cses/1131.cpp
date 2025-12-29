#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Common competitive programming typedefs
typedef long long ll;

const int INF = 1e9;



pair<int, int> bfs(vector<vector<int>>& graph, int n, int source) {
  vector<int> dis(n+1, INF);
  queue<int> q;
  dis[source] = 0;
  q.push(source);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : graph[u]) {
      if (dis[v] == INF) {
        dis[v] = dis[u] + 1;
        q.push(v);
      } else if (dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
      }
    }
  }

  int d = 0;
  int v = source;
  for (int i = 1; i <= n; i++) {
    if (dis[i] > d) {
      d = dis[i], v = i;
    }
  }

  return make_pair(d, v);
 
}


int main() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n+1);
  int e = n - 1;
  while (e--) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  pair<int, int> p = bfs(graph, n, 1);
  pair<int, int> q = bfs(graph, n, p.second);
  cout << q.first << endl;
  
  return 0;
}