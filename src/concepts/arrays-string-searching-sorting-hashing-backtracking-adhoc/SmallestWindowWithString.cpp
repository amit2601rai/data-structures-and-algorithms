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

// Returns false if no valid window is found. Else returns
// true and updates minWindowBegin and minWindowEnd with the
// starting and ending position of the minimum window.
bool minWindow(const char *S, const char *T, int &minWindowBegin, int &minWindowEnd) {
  int sLen = strlen(S);
  int tLen = strlen(T);
  int needToFind[256] = {0};

  for (int i = 0; i < tLen; i++) needToFind[T[i]]++;

  int hasFound[256] = {0};
  int minWindowLen = INT_MAX;
  int count = 0;
  for (int begin = 0, end = 0; end < sLen; end++) {
    // skip characters not in T
    if (needToFind[S[end]] == 0) continue;
    hasFound[S[end]]++;
    if (hasFound[S[end]] <= needToFind[S[end]]) count++;

    // if window constraint is satisfied
    if (count == tLen) {
      // advance begin index as far right as possible,
      // stop when advancing breaks window constraint.
      while (needToFind[S[begin]] == 0 || hasFound[S[begin]] > needToFind[S[begin]]) {
        if (hasFound[S[begin]] > needToFind[S[begin]]) hasFound[S[begin]]--;
        begin++;
      }
      // update minWindow if a minimum length is met
      int windowLen = end - begin + 1;
      if (windowLen < minWindowLen) {
        minWindowBegin = begin;
        minWindowEnd = end;
        minWindowLen = windowLen;
      }
    }
  }
  return (count == tLen) ? true : false;
}

int main() {
  char text[101];
  char pattern[51];
  int minWindwowBegin, minWindowEnd;
  cin >> text;
  cin >> pattern;
  minWindow(text, pattern, minWindowBegin, minWindowEnd);
  return 0;
}
