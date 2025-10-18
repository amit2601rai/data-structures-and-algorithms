/*Binary Tree Common Header - Self-sufficient for all binary tree algorithms*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

// Binary Tree Node Structure
struct BtreeNode {
    int data;
    struct BtreeNode *left;
    struct BtreeNode *right;
};

typedef struct BtreeNode* node;

// Utility function to create a new node
inline node getNewNode() {
    node tmp;
    tmp = (node)malloc(sizeof(struct BtreeNode));
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

// Creates a sample binary tree for testing algorithms
inline struct BtreeNode* construction_BT() {
    struct BtreeNode *root,*p,*r,*s,*t,*u,*q;
    root=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    root->data=21;
    root->left=NULL;
    root->right=NULL;

    p=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    p->data=12;
    p->left=NULL;
    p->right=NULL;
    q=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    q->data=29;
    q->left=NULL;
    q->right=NULL;
    root->left=p;
    root->right=q;

    s=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    s->data=24;
    s->left=NULL;
    s->right=NULL;
    p->left=s;
    s=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    s->data=26;
    s->left=NULL;
    s->right=NULL;
    p->right=s;
    t=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    t->data=27;
    t->left=NULL;
    t->right=NULL;
    u=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    u->data=28;
    u->left=NULL;
    u->right=NULL;
    s->left=t;
    s->right=u;
    p=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    p->data=100;
    p->left=NULL;
    p->right=NULL;
    r=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    r->data=101;
    r->left=NULL;
    r->right=NULL;
    q->left=p;
    q->right=r;
    r=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    r->data=4;
    r->left=NULL;
    r->right=NULL;
    s=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    s->data=5;
    s->left=NULL;
    s->right=NULL;
    p->left=r;
    p->right=s;
    p=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    q=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    p->data=7;
    p->left=NULL;
    p->right=NULL;
    q->data=10;
    q->left=NULL;
    q->right=NULL;
    s->left=p;
    s->right=q;
    t=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    u=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));
    t->data=9;
    t->left=NULL;
    t->right=NULL;
    u->data=8;
    u->left=NULL;
    u->right=NULL;
    q->left=t;
    q->right=u;
    return root;
}

// Utility function to setup a tree for testing
inline node setupTree() {
    node root = NULL;
    root = construction_BT();
    return root;
}