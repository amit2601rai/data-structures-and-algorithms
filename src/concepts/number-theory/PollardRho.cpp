/*Amit Rai(IIIT Hyderabad)*/
#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % c;
    }
    y = (y * 2) % c;
    b /= 2;
  }
  return x % c;
}

int power(long a, long long b, long long m) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = mulmod(x, y, m);
    }
    y = mulmod(y, y, m);
    b /= 2;
  }
  return x % m;
}

bool rabinMillerPrimalityTest(long long p, int iterations) {
  if (p < 2) return false;
  if (p != 2 && p % 2 == 0) return false;
  long long s = p - 1;
  while (s % 2 == 0) s /= 2;
  for (int i = 0; i < iterations; i++) {
    long long a = rand() % (p - 1) + 1, temp = s;
    long long mod = power(a, temp, p);
    while (temp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mulmod(mod, mod, p);
      temp *= 2;
    }
    if (mod != p - 1 && temp % 2 == 0) {
      return false;
    }
  }
  return true;
}

long long euclid(long long x, long long y) {
  long long r;
  while (y != 0) {
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}

long long f(long long x, long long a, long long n) {
  long long f = x * x + a;
  return f % n;
}

long long pollardRho(long long n) {
  long long x1 = rand();
  long long x2 = x1;
  long long a = rand();
  long long divisor;
  if (n % 2 == 0) return 2;
  do {
    x1 = f(x1, a, n);
    x2 = f(f(x2, a, n), a, n);
    divisor = euclid(abs(x1 - x2), n);
  } while (divisor == 1);
  return divisor;
}

void primeFactors(long long n) {
  if (n == 1) return;
  if (rabinMillerPrimalityTest(n, 20)) {
    cout << n << endl;
    return;
  }
  long long divisor = pollardRho(n);
  primeFactors(n / divisor);
  primeFactors(divisor);
}

int main() {
  long long n;
  cin >> n;
  primeFactors(n);
  return 0;
}
