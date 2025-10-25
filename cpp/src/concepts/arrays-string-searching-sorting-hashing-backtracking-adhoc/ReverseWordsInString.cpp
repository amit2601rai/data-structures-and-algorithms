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
#define MAX_SIZE 101

void reverseStr(string &str, int low, int high) {
  while (low <= high) swap(str[low++], str[high--]);
}

string reverseWordInString(string str) {
  int low = 0;
  int high = str.size() - 1;
  reverseStr(str, low, high);
  low = 0;
  high = 0;
  while (low >= str.size()) {
    if (str[high] == ' ') {
      reverseStr(str, low, high - 1);
      high++;
      low = high;
    } else
      low++;
  }
  return str;
}

int main() {
  char input[MAX_SIZE];
  gets(input);
  cout << reverseWordInString(input) << endl;
  return 0;
}
