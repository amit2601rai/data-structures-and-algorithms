#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct heap {
  int *array;
  int capacity;
  int size;
};
typedef struct heap *maxHeap;

/** Heap Creation (Max Heap) : capacity **/
maxHeap Create(int capacity) {
  maxHeap h = (struct heap *)malloc(sizeof(struct heap));
  if (h == NULL) {
    cout << "Memory Error" << endl;
    return NULL;
  }
  h->size = 0;
  h->capacity = capacity;
  h->array = (int *)malloc(sizeof(int) * capacity);
  if (h->array == NULL) {
    cout << "Memory Error" << endl;
    return NULL;
  }
  return h;
}

/**Print Heap**/
void print_heap(maxHeap h) {
  for (int i = 0; i < h->size; i++) {
    cout << h->array[i] << " ";
  }
  cout << endl;
}

/**Getting Maximum Element (Max Heap) **/
int GetMaximum(maxHeap h) {
  if (h->size == 0) return -1;
  return h->array[0];
}

/**Getting Minimum Element (Min Heap)**/
int GetMinimum(maxHeap h) {
  if (h->size == 0) return -1;
  return h->array[0];
}

/**Getting Left Child**/
int GetLeftChild(maxHeap h, int i) {
  int left = 2 * i + 1;
  if (h->size > left)
    return left;
  else
    return -1;
}

/**Getting Parent**/
int GetParent(maxHeap h, int i) {
  if (i == 0)
    return -1;
  else
    return h->array[(i - 1) / 2];
}

/**Getting Right Child**/
int GetRightChild(maxHeap h, int i) {
  int right = 2 * i + 2;
  if (h->size > right)
    return right;
  else
    return -1;
}

/** Heapify : Maintaining Heap property **/
void heapify(maxHeap h, int i) {
  int l = GetLeftChild(h, i);
  int r = GetRightChild(h, i);
  if (l == -1 && r == -1) return;
  int max_index, temp;
  max_index = i;
  if (l != -1 && h->array[l] > h->array[i]) max_index = l;
  if (r != -1 && h->array[r] > h->array[max_index]) max_index = r;
  if (max_index != i) {
    temp = h->array[i];
    h->array[i] = h->array[max_index];
    h->array[max_index] = temp;
    heapify(h, max_index);
  }
}

/** Insertion : O(logn) **/
void insert(maxHeap h, int val) {
  int i, temp;
  i = h->size;
  h->array[i] = val;
  h->size++;
  while (i != 0 && GetParent(h, i) < h->array[i]) {
    temp = GetParent(h, i);
    h->array[(i - 1) / 2] = h->array[i];
    h->array[i] = temp;
    i = (i - 1) / 2;
  }
}

/** Deletion : O(logn) **/
void deletion(maxHeap h) {
  if (h->size == 0)
    cout << "Empty Heap" << endl;
  else {
    h->array[0] = h->array[h->size - 1];
    h->size--;
    heapify(h, 0);
  }
}

int main() {
  int capacity;
  cin >> capacity;
  maxHeap h = Create(capacity);
  insert(h, 3);
  insert(h, 10);
  insert(h, 7);
  insert(h, 9);
  insert(h, 8);
  insert(h, 6);
  insert(h, 44);
  insert(h, 30);
  insert(h, 13);
  insert(h, 33);
  deletion(h);
  print_heap(h);
  return 0;
}
