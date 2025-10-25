/*Amit Rai(IIIT Hyderabad)*/
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<int, int> mi;
typedef set<int> si;
typedef priority_queue<int, vi, greater<int> > minHeap;
typedef priority_queue<int> maxHeap;
typedef priority_queue<ii, vii, greater<ii> > pminHeap;
typedef priority_queue<ii> pmaxHeap;

#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define init_1D(a, n, value) FOR(i, 0, n) a[i] = value;
#define init_2D(a, m, n, value) FOR(i, 0, m) FOR(j, 0, n) a[i][j] = value;
#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define setp(v, n) \
  cout << fixed;   \
  cout << setprecision(n) << v << endl;
#define all(c) (c).begin(), (c).end()
#define tr(c, it) for (typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

int main() {
  string input;
  cin >> input;
  bool hash[256];
  init_1D(hash, 255, false);
  int ans = 0, max_so_far = 0;
  int s, e;
  int len = input.size();
  s = 0;
  e = 0;
  while (e < len) {
    if (s == e) {
      hash[input[e]] = true;
      max_so_far = 1;
      e++;
    } else if (!hash[input[e]]) {
      hash[input[e]] = true;
      max_so_far++;
      e++;
    } else {
      ans = max(ans, max_so_far);
      hash[input[s]] = false;
      max_so_far--;
      s++;
    }
  }
  ans = max(ans, max_so_far);
  cout << ans << endl;
  return 0;
}
