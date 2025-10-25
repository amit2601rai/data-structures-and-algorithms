/*Amit Rai(IIIT Hyderabad)*/
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
typedef priority_queue<ii, vector<ii>, greater<ii> > minHeap;
typedef priority_queue<ii> maxHeap;

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

const static int MAX = 100;

int par[MAX + 1];
int rnk[MAX + 1];

void createSet(int x) {
  par[x] = x;
  rnk[x] = 0;
}

int findSet(int x) {
  if (x != par[x]) par[x] = findSet(par[x]);
  return par[x];
}

void mergeSet(int x, int y) {
  int repX = findSet(x);
  int repY = findSet(y);
  if (rnk[repX] > rnk[repY])
    par[repY] = repX;
  else
    par[repX] = repY;
  if (rnk[repX] == rnk[repY]) rnk[repY] += 1;
}

/*Testing Code*/
int main() {
  int n, q, x, y, t;
  s(n);
  FOR(i, 1, n) createSet(i);
  s(q);
  while (q--) {
    s(t);
    s(x);
    s(y);
    if (t) {
      if (findSet(x) != findSet(y)) mergeSet(x, y);
    }
    if (!t) {
      if (findSet(x) == findSet(y)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
