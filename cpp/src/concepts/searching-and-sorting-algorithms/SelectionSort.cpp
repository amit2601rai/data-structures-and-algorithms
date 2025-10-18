#include <cstdio>
#include <iostream>

using namespace std;

void print(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}

void selectionsort(int a[], int n) {
  int min_index;
  for (int i = 0; i < n; i++) {
    min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (a[min_index] > a[j]) min_index = j;
    }
    int temp = a[i];
    a[i] = a[min_index];
    a[min_index] = temp;
  }
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  selectionsort(a, n);
  print(a, n);
  return 0;
}
