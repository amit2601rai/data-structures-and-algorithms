#include "LinkedListCommon.h"

struct StackWithMiddle {
  Dnode top = NULL;
  Dnode middle = NULL;
  int size = 0;
};

typedef StackWithMiddle MStack;

Dnode getTop(MStack* s) { return (s->size != 0 ? s->top : NULL); }

Dnode getMiddle(MStack* s) { return (s->size != 0 ? s->middle : NULL); }

void pop(MStack* s) {
  if (s->size == 0) return;

  Dnode tmp = s->top;
  s->top = s->top->next;
  if (s->top) s->top->prev = NULL;

  free(tmp);
  s->size--;

  if (s->size % 2 == 0) {
    s->middle = s->middle->next;
  }
}

void push(MStack* s, int x) {
  Dnode newNode = getNewDnode(x);

  if (s->top == NULL) {
    s->top = newNode;
    s->middle = newNode;
    s->size++;
    return;
  }

  newNode->next = s->top;
  s->top->prev = newNode;
  s->top = newNode;
  s->size++;

  if (s->size % 2 != 0) {
    s->middle = s->middle->prev;
  }
}

int main() {
  MStack stack = {NULL, NULL, 0};

  push(&stack, 1);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  push(&stack, 2);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  push(&stack, 3);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  push(&stack, 4);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  push(&stack, 5);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  pop(&stack);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  pop(&stack);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  pop(&stack);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  pop(&stack);
  cout << "Middle = " << getMiddle(&stack)->data << endl;
  pop(&stack);
  Dnode t = getMiddle(&stack);
  if (t)
    cout << "Middle = " << t->data << endl;
  else
    cout << "Stack is empty" << endl;

  return 0;
}
