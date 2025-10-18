#include <algorithm>
#include <iostream>

#define print(a, n) \
  for (int i = 0; i < n; i++) cout << a[i] << " ";

using namespace std;

/*
start To low : 0s
low+1 mid-1 : 1s
high To end : 2s
*/
void dutchNationalFlagProblem(int a[], int n) {
  int i = 0, j = n - 1;
  int low = -1, high = n;
  while (a[i] == 0) {
    low = i;
    i++;
  }
  while (a[j] == 2) {
    high = j;
    j--;
  }
  int mid = low + 1;
  while (mid < high) {
    if (a[mid] == 0) {
      a[++low] = 0;
      a[mid] = 1;
      mid++;
    } else if (a[mid] == 1)
      mid++;
    else {
      swap(a[mid], a[--high]);
      a[high] = 2;
    }
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  dutchNationalFlagProblem(a, n);
  print(a, n);
  return 0;
}
