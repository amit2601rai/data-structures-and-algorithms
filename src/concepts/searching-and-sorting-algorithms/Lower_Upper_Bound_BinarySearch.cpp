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

/*
Returns first index of element and -1 if it's not found
*/
int firstIndex(int a[], int n, int key) {
  int low, high;
  low = 0;
  high = n - 1;
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (a[mid] == key)
      high = mid;
    else if (a[mid] > key)
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (a[low] == key)
    return low;
  else if (a[high] == key)
    return high;
  else
    return -1;
}

/*
Returns last index of element and -1 if it's not found
*/
int lastIndex(int a[], int n, int key) {
  int low, high;
  low = 0;
  high = n - 1;
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (a[mid] == key)
      low = mid;
    else if (a[mid] > key)
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (a[high] == key)
    return high;
  else if (a[low] == key)
    return low;
  else
    return -1;
}

/*
Returns index of first element greater than key and -1 if it's not found
*/
int firstElementGreater(int a[], int n, int key) {
  int low = 0, high = n - 1;
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (a[mid] <= key)
      low = mid + 1;
    else if (a[mid] > key)
      high = mid;
  }
  if (a[low] > key)
    return low;
  else if (a[high] > key)
    return high;
  else
    return -1;
}

/*
Returns index of last element smaller than key and -1 if it's not found
*/
int lastElementSmaller(int a[], int n, int key) {
  int low = 0, high = n - 1;
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (a[mid] < key)
      low = mid;
    else
      high = mid - 1;
  }
  if (a[high] < key)
    return high;
  else if (a[low] < key)
    return low;
  else
    return -1;
}

int main() {
  int n, key;
  cin >> n >> key;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int idx1 = firstIndex(a, n, key);
  int idx2 = lastIndex(a, n, key);
  int idx3 = firstElementGreater(a, n, key);
  int idx4 = lastElementSmaller(a, n, key);
  cout << idx1 << " " << idx2 << " " << idx3 << " " << idx4 << endl;
  return 0;
}
