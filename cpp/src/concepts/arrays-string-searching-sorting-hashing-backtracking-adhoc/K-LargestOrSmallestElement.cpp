#include <iostream>
#include <queue>

using namespace std;

void kSmallest(int a[], int n, int k) {
  priority_queue<int> Q;  // max-heap
  for (int i = 0; i < n; i++) {
    if (i < k)
      Q.push(a[i]);
    else {
      if (Q.top() > a[i]) {
        Q.pop();
        Q.push(a[i]);
      }
    }
  }
  while (!Q.empty()) {
    cout << Q.top() << " ";
    Q.pop();
  }
  cout << endl;
}

void kLargest(int a[], int n, int k) {
  priority_queue<int, vector<int>, greater<int> > Q;  // min-heap
  for (int i = 0; i < n; i++) {
    if (i < k)
      Q.push(a[i]);
    else {
      if (Q.top() < a[i]) {
        Q.pop();
        Q.push(a[i]);
      }
    }
  }
  while (!Q.empty()) {
    cout << Q.top() << " ";
    Q.pop();
  }
  cout << endl;
}

int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  kLargest(a, n, k);
  kSmallest(a, n, k);
  return 0;
}
