#include <cstdio>
#include <iostream>

using namespace std;

void print(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}

int partition(int a[], int low, int high) {
  int x = a[high];  // select pivot element
  int i = low - 1;
  for (int j = low; j < high; j++)
    if (a[j] < x) swap(a[++i], a[j]);
  swap(a[i + 1], a[high]);
  return i + 1;
}

void quicksort(int a[], int low, int high) {
  if (low < high) {
    int p = partition(a, low, high);
    quicksort(a, low, p - 1);
    quicksort(a, p + 1, high);
  }
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  quicksort(a, 0, n - 1);
  print(a, n);
  return 0;
}
