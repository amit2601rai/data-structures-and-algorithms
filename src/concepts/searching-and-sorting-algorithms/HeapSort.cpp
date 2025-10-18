#include <cstdio>
#include <iostream>

using namespace std;

void print(int a[], int low, int high) {
  for (int i = low; i <= high; i++) cout << a[i] << " ";
  cout << endl;
}

void heapify(int a[], int i, int size) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int max_index = i;
  if (left > size - 1 && right > size - 1) return;
  if (left <= size - 1) {
    if (a[left] > a[max_index]) {
      max_index = left;
    }
  }
  if (right <= size - 1) {
    if (a[right] > a[max_index]) {
      max_index = right;
    }
  }
  if (max_index != i) {
    int temp = a[i];
    a[i] = a[max_index];
    a[max_index] = temp;
    heapify(a, max_index, size);
  }
}

void buildmaxheap(int a[], int size) {
  for (int i = (size - 1) / 2; i >= 0; i--) heapify(a, i, size);
}

void heapsort(int a[], int h_size) {
  buildmaxheap(a, h_size);
  for (int i = h_size - 1; i > 0; i--) {
    int temp = a[h_size - 1];
    a[h_size - 1] = a[0];
    a[0] = temp;
    h_size--;
    heapify(a, 0, h_size);
  }
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  heapsort(a, n);
  print(a, 0, n - 1);
  return 0;
}
