#include "LinkedListCommon.h"

int getLength(Node head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node findIntersection(Node p, Node q) {
    int lenP = getLength(p);
    int lenQ = getLength(q);
    int diff;
    
    if (lenP > lenQ) {
        diff = lenP - lenQ;
        while (diff--) {
            p = p->next;
        }
    } else {
        diff = lenQ - lenP;
        while (diff--) {
            q = q->next;
        }
    }
    
    while (p && q) {
        if (p == q) return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}

int main() {
    // Create first list: 1->2->3->4->5
    Node list1 = getNewNode(1);
    list1->next = getNewNode(2);
    list1->next->next = getNewNode(3);
    
    // Create intersection part: 4->5
    Node intersection = getNewNode(4);
    intersection->next = getNewNode(5);
    
    // Connect first list to intersection
    list1->next->next->next = intersection;
    
    // Create second list: 6->7->4->5 (shares 4->5 with first list)
    Node list2 = getNewNode(6);
    list2->next = getNewNode(7);
    list2->next->next = intersection; // Same intersection point
    
    cout << "List 1: ";
    printList(list1);
    
    cout << "List 2: ";
    printList(list2);
    
    Node intersectionPoint = findIntersection(list1, list2);
    
    if (intersectionPoint) {
        cout << "Intersection point found at node with value: " << intersectionPoint->data << endl;
    } else {
        cout << "No intersection point found." << endl;
    }
    
    return 0;
}
