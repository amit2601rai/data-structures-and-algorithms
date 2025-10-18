#include "LinkedListCommon.h"
#include <map>

struct ArbitNode {
    int data;
    ArbitNode* next;
    ArbitNode* arbit;  // Random/arbitrary pointer
};

ArbitNode* getNewArbitNode(int data) {
    ArbitNode* tmp = (ArbitNode*)malloc(sizeof(ArbitNode));
    tmp->data = data;
    tmp->next = NULL;
    tmp->arbit = NULL;
    return tmp;
}

void printArbitList(ArbitNode* head) {
    ArbitNode* temp = head;
    while (temp) {
        cout << "Data: " << temp->data;
        if (temp->arbit) {
            cout << ", Arbit: " << temp->arbit->data;
        } else {
            cout << ", Arbit: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

/**
 * Method 1: Using Extra Space (Hash Map)
 * Time Complexity: O(n)
 * Auxiliary Space: O(n)
 */
ArbitNode* cloneWithMap(ArbitNode* head) {
    if (head == NULL) return NULL;
    
    map<ArbitNode*, ArbitNode*> nodeMap;
    ArbitNode* current = head;
    
    // First pass: create all nodes and store mapping
    while (current) {
        nodeMap[current] = getNewArbitNode(current->data);
        current = current->next;
    }
    
    // Second pass: set next and arbit pointers
    current = head;
    while (current) {
        if (current->next) {
            nodeMap[current]->next = nodeMap[current->next];
        }
        if (current->arbit) {
            nodeMap[current]->arbit = nodeMap[current->arbit];
        }
        current = current->next;
    }
    
    return nodeMap[head];
}

/**
 * Method 2: Using Constant Space
 * Time Complexity: O(n)
 * Auxiliary Space: O(1)
 */
ArbitNode* cloneConstantSpace(ArbitNode* head) {
    if (head == NULL) return NULL;
    
    // Step 1: Create copy nodes and insert them after original nodes
    ArbitNode* current = head;
    while (current) {
        ArbitNode* copy = getNewArbitNode(current->data);
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }
    
    // Step 2: Set arbit pointers for copy nodes
    current = head;
    while (current) {
        if (current->arbit) {
            current->next->arbit = current->arbit->next;
        }
        current = current->next->next;
    }
    
    // Step 3: Separate original and copy lists
    ArbitNode* original = head;
    ArbitNode* copyHead = head->next;
    ArbitNode* copy = copyHead;
    
    while (original && copy) {
        original->next = copy->next;
        original = original->next;
        
        if (original) {
            copy->next = original->next;
            copy = copy->next;
        }
    }
    
    return copyHead;
}

int main() {
    // Create a linked list with arbitrary pointers
    // 1 -> 2 -> 3 -> 4 -> 5
    ArbitNode* head = getNewArbitNode(1);
    head->next = getNewArbitNode(2);
    head->next->next = getNewArbitNode(3);
    head->next->next->next = getNewArbitNode(4);
    head->next->next->next->next = getNewArbitNode(5);
    
    // Set some arbitrary pointers
    head->arbit = head->next->next;           // 1 -> 3
    head->next->arbit = head;                 // 2 -> 1
    head->next->next->arbit = head->next->next->next->next; // 3 -> 5
    head->next->next->next->arbit = head->next->next; // 4 -> 3
    head->next->next->next->next->arbit = head->next; // 5 -> 2
    
    cout << "Original list:" << endl;
    printArbitList(head);
    
    // Test Method 1: Using hash map
    ArbitNode* cloned1 = cloneWithMap(head);
    cout << "\nCloned list (using map):" << endl;
    printArbitList(cloned1);
    
    // Test Method 2: Constant space
    ArbitNode* cloned2 = cloneConstantSpace(head);
    cout << "\nCloned list (constant space):" << endl;
    printArbitList(cloned2);
    
    return 0;
}