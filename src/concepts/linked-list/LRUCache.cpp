#include <unordered_map>

#include "LinkedListCommon.h"

class LRUCache {
 private:
  struct CacheNode {
    int key;
    int value;
    CacheNode* prev;
    CacheNode* next;

    CacheNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
  };

  int capacity;
  unordered_map<int, CacheNode*> cache;
  CacheNode* head;
  CacheNode* tail;

  void addNode(CacheNode* node) {
    // Add node right after head
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  void removeNode(CacheNode* node) {
    // Remove an existing node from the linked list
    CacheNode* prevNode = node->prev;
    CacheNode* nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

  void moveToHead(CacheNode* node) {
    // Move certain node to head
    removeNode(node);
    addNode(node);
  }

  CacheNode* popTail() {
    // Pop the current tail
    CacheNode* lastNode = tail->prev;
    removeNode(lastNode);
    return lastNode;
  }

 public:
  LRUCache(int capacity) : capacity(capacity) {
    head = new CacheNode(0, 0);
    tail = new CacheNode(0, 0);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    CacheNode* node = cache[key];
    if (node == nullptr) {
      return -1;  // Not found
    }

    // Move the accessed node to head
    moveToHead(node);
    return node->value;
  }

  void put(int key, int value) {
    CacheNode* node = cache[key];

    if (node == nullptr) {
      CacheNode* newNode = new CacheNode(key, value);

      cache[key] = newNode;
      addNode(newNode);

      if (cache.size() > capacity) {
        // Pop the tail
        CacheNode* tail = popTail();
        cache.erase(tail->key);
        delete tail;
      }
    } else {
      // Update the value
      node->value = value;
      moveToHead(node);
    }
  }

  void display() {
    cout << "Cache contents (most recent first): ";
    CacheNode* current = head->next;
    while (current != tail) {
      cout << "(" << current->key << ":" << current->value << ") ";
      current = current->next;
    }
    cout << endl;
  }
};

int main() {
  LRUCache cache(2);  // Cache with capacity 2

  cache.put(1, 10);
  cache.put(2, 20);
  cache.display();

  cout << "Get key 1: " << cache.get(1) << endl;  // Returns 10
  cache.display();

  cache.put(3, 30);  // Evicts key 2
  cache.display();

  cout << "Get key 2: " << cache.get(2) << endl;  // Returns -1 (not found)
  cout << "Get key 3: " << cache.get(3) << endl;  // Returns 30
  cout << "Get key 1: " << cache.get(1) << endl;  // Returns 10
  cache.display();

  cache.put(4, 40);  // Evicts key 3
  cache.display();

  cout << "Get key 1: " << cache.get(1) << endl;  // Returns 10
  cout << "Get key 3: " << cache.get(3) << endl;  // Returns -1 (not found)
  cout << "Get key 4: " << cache.get(4) << endl;  // Returns 40

  return 0;
}