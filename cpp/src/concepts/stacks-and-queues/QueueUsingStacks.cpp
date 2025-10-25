/*Amit Rai(IIIT Hyderabad)*/
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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

template <class T>
class myQueue {
 private:
  stack<T> s1;
  stack<T> s2;

 public:
  void push(T x) { s1.push(x); }

  T pop() {
    T y;
    if (s1.empty() && s2.empty()) {
      cout << "Queue is empty" << endl;
    } else if (!s2.empty()) {
      y = s2.top();
      s2.pop();
    } else {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      y = s2.top();
      s2.pop();
    }
    return y;
  }
};

int main() {
  myQueue<int> Q;
  Q.push(1);
  Q.push(2);
  cout << Q.pop() << endl;
  Q.push(3);
  Q.push(4);
  cout << Q.pop() << endl;
  Q.push(5);
  Q.push(6);
  cout << Q.pop() << endl;
  cout << Q.pop() << endl;
  cout << Q.pop() << endl;
  cout << Q.pop() << endl;
  return 0;
}
