/*Amit Rai(IIIT Hyderabad)*/

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

class myStack {
 private:
  stack<int> elements;
  stack<int> minElement;
  stack<int> maxElement;

 public:
  void push(int x) {
    elements.push(x);
    if (minElement.empty())
      minElement.push(x);
    else
      minElement.push(min(minElement.top(), x));
    if (maxElement.empty())
      maxElement.push(x);
    else
      maxElement.push(max(maxElement.top(), x));
  }

  void pop() {
    if (!elements.empty()) elements.pop();
    if (!minElement.empty()) minElement.pop();
    if (!maxElement.empty()) maxElement.pop();
  }

  int top() {
    if (!elements.empty())
      return elements.top();
    else
      printf("Stack Is Empty !!!");
  }

  int getMin() {
    if (!minElement.empty())
      return minElement.top();
    else
      printf("Stack Is Empty !!!");
  }

  int getMax() {
    if (!maxElement.empty())
      return maxElement.top();
    else
      printf("Stack Is Empty !!!");
  }
};

int main() {
  // Testing Code
  return 0;
}
