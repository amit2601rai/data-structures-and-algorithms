#include <iostream>

using namespace std;

int binary_search(int a[], int low, int high, int key) {
  if (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)
      return binary_search(a, mid + 1, high, key);
    else
      return binary_search(a, low, mid - 1, key);
  }
  return -1;
}

int getRotationIndex(int a[], int n) {
  int low = 0, high = n - 1, mid = 0;
  while (low <= high) {
    mid = (low + high) / 2;
    if (a[low] < a[high])
      return low;
    else if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1])
      return mid;
    else if (a[low] > a[mid])
      high = mid;
    else
      low = mid + 1;
  }
}

int containsKey(int a[], int n, int key) {
  int index = getRotationIndex(a, n);
  index = binary_search(a, 0, index - 1, key);
  if (index == -1)
    return binary_search(a, index, n - 1, key);
  else
    return index;
}

int main() {
  int n, key;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> key;
  cout << containsKey(a, n, key) << endl;
}
