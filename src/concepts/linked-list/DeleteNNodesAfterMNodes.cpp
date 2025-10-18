#include "LinkedListCommon.h"

Node deleteNAfterM(Node head, int m, int n) {
    if (head == NULL || m <= 0 || n <= 0) {
        return head;
    }
    
    Node current = head;
    
    while (current != NULL) {
        // Skip m nodes
        for (int i = 1; i < m && current != NULL; i++) {
            current = current->next;
        }
        
        if (current == NULL) {
            break;
        }
        
        // Delete n nodes
        Node nodeToDelete = current->next;
        for (int i = 1; i <= n && nodeToDelete != NULL; i++) {
            Node temp = nodeToDelete;
            nodeToDelete = nodeToDelete->next;
            free(temp);
        }
        
        // Connect the current node to the remaining list
        current->next = nodeToDelete;
        current = nodeToDelete;
    }
    
    return head;
}

int main() {
    // Create a list: 1->2->3->4->5->6->7->8->9->10
    Node head = getNewNode(1);
    Node current = head;
    for (int i = 2; i <= 10; i++) {
        current->next = getNewNode(i);
        current = current->next;
    }
    
    cout << "Original list: ";
    printList(head);
    
    int m = 2, n = 3; // Keep 2 nodes, delete 3 nodes
    head = deleteNAfterM(head, m, n);
    
    cout << "After deleting " << n << " nodes after every " << m << " nodes: ";
    printList(head);
    
    return 0;
}
