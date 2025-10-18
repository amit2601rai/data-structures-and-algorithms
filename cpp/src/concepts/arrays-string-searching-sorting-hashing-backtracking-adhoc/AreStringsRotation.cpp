/*Amit Rai(IIIT Hyderabad)*/
#include <bits/stdc++.h>

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

bool sortingMethod(string p, string q) {
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  return (p.compare(q) == 0);
}

bool hashMethod(string p, string q) {
  int hash1[256];
  int hash2[256];
  init_1D(hash1, 255, 0);
  init_1D(hash2, 255, 0);
  for (int i = 0; i < p.size(); i++) hash1[p[i]]++;
  for (int i = 0; i < q.size(); i++) hash2[q[i]]++;
  for (int i = 0; i < 256; i++)
    if (hash1[i] != hash2[i]) return false;
  return true;
}

int main() {
  string p, q;
  cin >> p >> q;
  if (hashMethod(p, q))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
