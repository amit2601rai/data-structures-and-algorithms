/**
Problem Statement : Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
**/

#include <iostream>

using namespace std;

void maximumOfSubArrayOfSizeK(int a[], int n, int k) {
  deque<int> dq;
  for (int i = 1; i < k; i++) {
    while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
    dq.push_back(i);
  }
  for (int i = k; i <= n; i++) {
    while (dq.front() < (i - k + 1)) dq.pop_front();
    while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
    dq.push_back(i);
    cout << a[dq.front()] << " ";
  }
  cout << endl;
}

int main() {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  maximumOfSubArrayOfSizeK(a, n, k);
  return 0;
}
