/*Amit Rai(IIIT Hyderabad)*/
#include <bits/stdc++.h>

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

/* List Of words are given, Print all anagrams together. */

bool myComp(pair<int, string> x, pair<int, string> y) { return ((x.second).compare(y.second) <= 0); }

void groupAnagrams(vector<string> v) {
  vector<pair<int, string> > vdup;
  for (int i = 0; i < v.size(); i++) {
    string tmp = v[i];
    sort(tmp.begin(), tmp.end());
    vdup.pb(mp(i, tmp));
  }
  sort(vdup.begin(), vdup.end(), myComp);
  for (int i = 0; i < vdup.size(); i++) {
    int x = vdup[i].first;
    cout << v[x] << endl;
  }
}

int main() {
  vector<string> v;
  int n;
  string x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.pb(x);
  }
  groupAnagrams(v);
  return 0;
}
