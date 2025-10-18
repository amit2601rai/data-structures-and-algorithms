#include "LinkedListCommon.h"

/* Insert at the begining */
struct node* insertatbeg(struct node* head, int x) {
  struct node* p;
  if (head == NULL) {
    p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    head = p;
  } else {
    p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = head;
    head = p;
  }
  return head;
}

/* Insert at the valid positions */
struct node* insertatpos(struct node* head, int pos, int x) {
  pos--;
  struct node *q, *r, *p;
  if (head == NULL) {
    if (pos != 1)
      return NULL;
    else {
      p = (struct node*)malloc(sizeof(struct node));
      p->data = x;
      p->next = NULL;
      head = p;
    }
  } else {
    q = NULL;
    r = head;
    for (int i = 1; i <= pos; i++) {
      q = r;
      r = r->next;
    }
    if (r == NULL) {
      struct node* s = (struct node*)malloc(sizeof(struct node));
      s->data = x;
      s->next = NULL;
      q->next = s;
    } else {
      struct node* s = (struct node*)malloc(sizeof(struct node));
      s->data = x;
      q->next = s;
      s->next = r;
    }
  }
  return head;
}

/*Insert at the end*/
struct node* insertatend(struct node* head, int x) {
  struct node* temp;
  temp = head;
  if (temp == NULL) {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    head = temp;
  } else {
    while (temp->next != NULL) temp = temp->next;
    temp->next = (struct node*)malloc(sizeof(struct node));
    temp->next->data = x;
    temp->next->next = NULL;
  }
  return head;
}

/*Insert using Double Pointer*/
void insertatbegdbp(struct node** ptr, int x) {
  if (*ptr == NULL) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    *ptr = temp;
  } else {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = *ptr;
    *ptr = temp;
  }
}

/*Insert using double pointer */
void insertatenddbp(struct node** ptr, int x) {
  if (*ptr == NULL) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    *ptr = temp;
  } else {
    struct node *temp, *r;
    temp = *ptr;
    while (temp->next != NULL) temp = temp->next;
    r = (struct node*)malloc(sizeof(struct node));
    r->data = x;
    r->next = NULL;
    temp->next = r;
  }
}

int main() {
  Node head = NULL;

  cout << "Testing different insertion methods:" << endl;

  // Insert at beginning
  head = insertatbeg(head, 10);
  head = insertatbeg(head, 20);
  head = insertatbeg(head, 30);
  cout << "After inserting 10, 20, 30 at beginning: ";
  printList(head);

  // Insert at end
  head = insertatend(head, 40);
  head = insertatend(head, 50);
  cout << "After inserting 40, 50 at end: ";
  printList(head);

  // Insert at position
  head = insertatpos(head, 25, 3);
  cout << "After inserting 25 at position 3: ";
  printList(head);

  return 0;
}
