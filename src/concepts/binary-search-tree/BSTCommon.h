#ifndef BST_COMMON_H
#define BST_COMMON_H

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

struct BtreeNode {
    int data;
    struct BtreeNode *left;
    struct BtreeNode *right;
};

typedef struct BtreeNode* node;

inline node getNewNode(int data = 0) {
    node tmp = (node)malloc(sizeof(struct BtreeNode));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

// Sample BST construction for testing
inline node constructSampleBST() {
    node root = getNewNode(50);
    root->left = getNewNode(30);
    root->right = getNewNode(70);
    root->left->left = getNewNode(20);
    root->left->right = getNewNode(40);
    root->right->left = getNewNode(60);
    root->right->right = getNewNode(80);
    root->left->left->left = getNewNode(10);
    root->left->right->right = getNewNode(45);
    return root;
}

inline node setupBST() {
    return constructSampleBST();
}

inline void inOrderTraversal(node root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

#endif // BST_COMMON_H