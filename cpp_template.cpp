/*
 * Author: Amit Rai (IIIT Hyderabad)
 * Modern C++ Competitive Programming Template
 * Includes all essential data structures, algorithms, and utilities
 */

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// ===== TYPE DEFINITIONS =====
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vb = vector<bool>;
using vs = vector<string>;

// ===== CONSTANTS =====
constexpr int MOD = 1e9 + 7;
constexpr int MOD2 = 998244353;
constexpr ll INF = 1e18;
constexpr int MAXN = 2e5 + 5;
constexpr double EPS = 1e-9;
const double PI = acos(-1.0);

// ===== FAST I/O =====
struct FastIO {
  FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
  }
} fast_io;

// ===== UTILITY MACROS =====
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

// Loop macros
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, (n) - 1, 0)

// Debug macros
#ifdef DEBUG
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debug2(x, y) \
  cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << '\n'
#else
#define debug(x)
#define debug2(x, y)
#endif

// ===== MATHEMATICAL UTILITIES =====
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}

template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template <typename T>
T power(T base, T exp, T mod = MOD) {
  T result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return result;
}

template <typename T>
T mod_inverse(T a, T mod = MOD) {
  return power(a, mod - 2, mod);
}

// ===== CONTAINER UTILITIES =====
template <typename T>
void sort_unique(vector<T> &v) {
  sort(all(v));
  v.erase(unique(all(v)), v.end());
}

template <typename T>
int lower_bound_index(const vector<T> &v, const T &val) {
  return lower_bound(all(v), val) - v.begin();
}

template <typename T>
int upper_bound_index(const vector<T> &v, const T &val) {
  return upper_bound(all(v), val) - v.begin();
}

// ===== ADVANCED DATA STRUCTURES =====

// Disjoint Set Union (Union-Find)
class DSU {
  vi parent, rank;

 public:
  DSU(int n) : parent(n), rank(n, 0) { iota(all(parent), 0); }

  int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    return true;
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

// Fenwick Tree (Binary Indexed Tree)
class FenwickTree {
  int n;
  vi tree;

 public:
  FenwickTree(int size) : n(size), tree(size + 1, 0) {}

  void update(int i, int delta) {
    for (++i; i <= n; i += i & -i) {
      tree[i] += delta;
    }
  }

  int query(int i) {
    int sum = 0;
    for (++i; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

  int range_query(int l, int r) {
    return query(r) - (l > 0 ? query(l - 1) : 0);
  }
};

// Segment Tree
class SegmentTree {
  vi tree, lazy;
  int n;

  void push(int node, int start, int end) {
    if (lazy[node] != 0) {
      tree[node] += lazy[node];
      if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }
      lazy[node] = 0;
    }
  }

  void update_range(int node, int start, int end, int l, int r, int val) {
    push(node, start, end);
    if (start > r || end < l) return;
    if (start >= l && end <= r) {
      lazy[node] += val;
      push(node, start, end);
      return;
    }
    int mid = (start + end) / 2;
    update_range(2 * node, start, mid, l, r, val);
    update_range(2 * node + 1, mid + 1, end, l, r, val);
    push(2 * node, start, mid);
    push(2 * node + 1, mid + 1, end);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }

  int query_range(int node, int start, int end, int l, int r) {
    if (start > r || end < l) return INT_MIN;
    push(node, start, end);
    if (start >= l && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return max(query_range(2 * node, start, mid, l, r),
               query_range(2 * node + 1, mid + 1, end, l, r));
  }

 public:
  SegmentTree(int size) : n(size) {
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
  }

  void update(int l, int r, int val) { update_range(1, 0, n - 1, l, r, val); }

  int query(int l, int r) { return query_range(1, 0, n - 1, l, r); }
};

// ===== GRAPH UTILITIES =====
using Graph = vector<vi>;
using WeightedGraph = vector<vpii>;

// DFS
void dfs(const Graph &g, int u, vb &visited) {
  visited[u] = true;
  for (int v : g[u]) {
    if (!visited[v]) {
      dfs(g, v, visited);
    }
  }
}

// BFS
vi bfs(const Graph &g, int start) {
  int n = sz(g);
  vi dist(n, -1);
  queue<int> q;
  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist;
}

// Dijkstra's shortest path
vll dijkstra(const WeightedGraph &g, int start) {
  int n = sz(g);
  vll dist(n, INF);
  priority_queue<pll, vpll, greater<pll>> pq;

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > dist[u]) continue;

    for (auto [v, w] : g[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

// ===== STRING UTILITIES =====
vi compute_lps(const string &pattern) {
  int m = sz(pattern);
  vi lps(m, 0);
  int len = 0, i = 1;

  while (i < m) {
    if (pattern[i] == pattern[len]) {
      lps[i++] = ++len;
    } else if (len != 0) {
      len = lps[len - 1];
    } else {
      lps[i++] = 0;
    }
  }
  return lps;
}

vi kmp_search(const string &text, const string &pattern) {
  vi matches;
  vi lps = compute_lps(pattern);
  int n = sz(text), m = sz(pattern);
  int i = 0, j = 0;

  while (i < n) {
    if (pattern[j] == text[i]) {
      i++, j++;
    }

    if (j == m) {
      matches.pb(i - j);
      j = lps[j - 1];
    } else if (i < n && pattern[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  return matches;
}

// ===== COMBINATORICS =====
class Combinatorics {
  int n;
  vll fact, inv_fact;

 public:
  Combinatorics(int size) : n(size), fact(size + 1), inv_fact(size + 1) {
    fact[0] = 1;
    FOR(i, 1, n + 1) { fact[i] = (fact[i - 1] * i) % MOD; }
    inv_fact[n] = mod_inverse(fact[n]);
    FORR(i, n - 1, 0) { inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD; }
  }

  ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (fact[n] * inv_fact[r] % MOD) * inv_fact[n - r] % MOD;
  }

  ll nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[n - r] % MOD;
  }
};

// ===== RANDOM UTILITIES =====
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
T random_int(T l, T r) {
  return uniform_int_distribution<T>(l, r)(rng);
}

template <typename T>
void shuffle_vector(vector<T> &v) {
  shuffle(all(v), rng);
}

// ===== MAIN FUNCTION =====
void solve() {
  // Your solution code goes here
}

int main() {
  int t = 1;
  // cin >> t;  // Uncomment for multiple test cases

  while (t--) {
    solve();
  }

  return 0;
}