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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
#define tr(type, container) \
  type ::iterator it;       \
  for (it = container.begin(); it != container.end(); it++)
#define setp(v, n) \
  cout << fixed;   \
  cout << setprecision(n) << v << endl;

map<int, char> M;

void prePareMap() {
  for (int i = 1; i <= 26; i++) {
    char x = i + 96;
    M[i] = x;
  }
}

void allNumbers(int a[], int start, string ans, int n) {
  if (start > n - 1) {
    cout << ans << endl;
    return;
  }
  string tmp = ans;
  tmp.append(1, M[a[start]]);
  allNumbers(a, start + 1, tmp, n);
  if (start + 1 <= n - 1) {
    int x = 10 * a[start] + a[start + 1];
    tmp = ans;
    if (M.find(x) != M.end()) {
      tmp.append(1, M[x]);
      allNumbers(a, start + 2, tmp, n);
    }
  }
}

int main() {
  prePareMap();
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  string ans = "";
  allNumbers(a, 0, ans, n);
  return 0;
}
