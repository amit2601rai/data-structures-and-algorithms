#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

void aux(int a[], int &low, int &high, int &first, int &second, int &zero) {
  if (abs(a[low] + a[high]) < zero) {
    zero = abs(a[low] + a[high]);
    first = low;
    second = high;
  }
}

void sumCloseTOZero(int a[], int n) {
  sort(a, a + n);
  int low = 0, high = n - 1;
  int first, second, zero = INT_MAX;
  while (low < high) {
    if (a[low] + a[high] == 0) {
      first = low;
      second = high;
      zero = 0;
      break;
    } else if (a[low] + a[high] < 0) {
      aux(a, low, high, first, second, zero);
      low++;
    } else {
      aux(a, low, high, first, second, zero);
      high--;
    }
  }
  cout << a[first] << " " << a[second] << " " << zero << endl;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sumCloseTOZero(a, n);
  return 0;
}
