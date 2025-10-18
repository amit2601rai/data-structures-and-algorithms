/*
Problem Statement:
A) Given an array A of integers, find the maximum of j-i subjected to the constraint of A[i] < A[j].
B) Given an array A of integers, find the maximum of j-i subjected to the constraint of A[i] > A[j].
*/

#include <climits>
#include <iostream>

using namespace std;

int solutionA(int arr[], int n) {
  int maxDiff;
  int i, j;
  int *LMin = new int[n];
  int *RMax = new int[n];

  /* Construct LMin[] such that LMin[i] stores the minimum value from (arr[0], arr[1], ... arr[i]) */
  LMin[0] = arr[0];
  for (i = 1; i < n; ++i) LMin[i] = min(arr[i], LMin[i - 1]);

  /* Construct RMax[] such that RMax[j] stores the maximum value from (arr[j], arr[j+1], ..arr[n-1]) */
  RMax[n - 1] = arr[n - 1];
  for (j = n - 2; j >= 0; --j) RMax[j] = max(arr[j], RMax[j + 1]);

  /* Traverse both arrays from left to right to find optimum j - i. This process is similar to merge() of MergeSort */
  i = 0, j = 0, maxDiff = -1;
  while (j < n && i < n) {
    if (LMin[i] < RMax[j]) {
      maxDiff = max(maxDiff, j - i);
      j = j + 1;
    } else
      i = i + 1;
  }
  return maxDiff;
}

int main() {
  int n;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << solutionA(a, n) << endl;
  return 0;
}
