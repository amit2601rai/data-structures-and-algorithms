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

string intToRoman(int num) {
  string ans = "";
  int ks[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  map<int, string> Map;
  Map[1000] = "M";
  Map[900] = "CM";
  Map[500] = "D";
  Map[400] = "CD";
  Map[100] = "C";
  Map[90] = "XC";
  Map[50] = "L";
  Map[40] = "XL";
  Map[10] = "X";
  Map[9] = "IX";
  Map[5] = "V";
  Map[4] = "IV";
  Map[1] = "I";
  int n = sizeof(ks) / sizeof(int);
  for (int i = 0; i < n;) {
    if (ks[i] <= num) {
      ans.append(Map[ks[i]]);
      num -= ks[i];
    } else
      i++;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << intToRoman(n) << endl;
  return 0;
}
