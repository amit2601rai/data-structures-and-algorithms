#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> q;
  int n;
  cin >> n;
  int a[n + 1];
  int b[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    while (!q.empty() && a[q.top()] < a[i]) {
      b[q.top()] = i;
      q.pop();
    }
    q.push(i);
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}
