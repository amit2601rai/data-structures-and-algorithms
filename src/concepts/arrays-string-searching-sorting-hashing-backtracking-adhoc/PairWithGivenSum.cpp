#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n, sum;
  cin >> n >> sum;
  int flag = 0;
  int a[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int low = 0, high = n - 1;
  while (low < high) {
    if (a[low] + a[high] == sum) {
      flag = 1;
      break;
    } else if (a[low] + a[high] < sum)
      low++;
    else
      high--;
  }
  if (flag)
    cout << "True" << endl;
  else
    cout << "False" << endl;
  return 0;
}
