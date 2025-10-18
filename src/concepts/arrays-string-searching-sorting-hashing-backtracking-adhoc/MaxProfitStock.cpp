/*Amit Rai(IIIT Hyderabad)*/
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<int, int> mi;
typedef set<int> si;
typedef priority_queue<int, vi, greater<int>> minHeap;
typedef priority_queue<int> maxHeap;
typedef priority_queue<ii, vii, greater<ii>> pminHeap;
typedef priority_queue<ii> pmaxHeap;

#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define init_1D(a, n, value) FOR(i, 0, n) a[i] = value;
#define init_2D(a, m, n, value) FOR(i, 0, m) FOR(j, 0, n) a[i][j] = value;
#define s(x) scanf("%d", &x)
#define p(x) printf("%d\n", x)
#define tr(type, container) \
  type ::iterator it;       \
  for (it = container.begin(); it != container.end(); it++)
#define setp(v, n) \
  cout << fixed;   \
  cout << setprecision(n) << v << endl;

int main() {
  int n;
  cin >> n;
  int stock[n];
  FOR(i, 0, n - 1) { cin >> stock[i]; }
  int ans = INT_MIN;
  int minPrice = stock[0];
  FOR(i, 1, n - 1) {
    if (stock[i] < minPrice) {
      ans = max(ans, stock[i] - minPrice);
      minPrice = stock[i];
    } else {
      ans = max(ans, stock[i] - minPrice);
    }
  }
  cout << ans << endl;
  return 0;
}
