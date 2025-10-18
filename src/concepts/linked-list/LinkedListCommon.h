#ifndef LINKED_LIST_COMMON_H
#define LINKED_LIST_COMMON_H

// Use bits/stdc++.h for compilation, but include individual headers for IDE support
#ifdef __has_include
    #if __has_include(<bits/stdc++.h>)
        #include <bits/stdc++.h>
    #else
        #include <iostream>
        #include <stack>
        #include <queue>
        #include <vector>
        #include <algorithm>
        #include <cstdlib>
        #include <climits>
    #endif
#else
    #include <bits/stdc++.h>
#endif

using namespace std;

// Singly Linked List Node
struct node {
    int data;
    struct node *next;
};

// Doubly Linked List Node  
struct dnode {
    int data;
    struct dnode *prev;
    struct dnode *next;
};

typedef struct node* Node;
typedef struct dnode* Dnode;

inline Node getNewNode(int data) {
    Node tmp = (Node)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

inline Dnode getNewDnode(int data) {
    Dnode tmp = (Dnode)malloc(sizeof(struct dnode));
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

// Create a sample singly linked list for testing
inline Node constructSampleList() {
    Node head = getNewNode(1);
    head->next = getNewNode(2);
    head->next->next = getNewNode(3);
    head->next->next->next = getNewNode(4);
    head->next->next->next->next = getNewNode(5);
    return head;
}

// Create a sample doubly linked list for testing
inline Dnode constructSampleDList() {
    Dnode head = getNewDnode(1);
    head->next = getNewDnode(2);
    head->next->prev = head;
    head->next->next = getNewDnode(3);
    head->next->next->prev = head->next;
    head->next->next->next = getNewDnode(4);
    head->next->next->next->prev = head->next->next;
    return head;
}

inline Node setupList() {
    return constructSampleList();
}

inline Dnode setupDList() {
    return constructSampleDList();
}

inline void printList(Node head) {
    Node current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

inline void printDList(Dnode head) {
    Dnode current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

#endif // LINKED_LIST_COMMON_H