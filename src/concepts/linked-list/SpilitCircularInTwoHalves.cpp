#include "LinkedListCommon.h"

Node splitCircularList(Node head, Node* secondHead) {
    if (head == NULL) {
        *secondHead = NULL;
        return NULL;
    }
    
    if (head->next == head) {
        *secondHead = NULL;
        return head;
    }
    
    // Find the middle using slow and fast pointers
    Node slow = head;
    Node fast = head;
    
    // Move fast pointer two steps and slow pointer one step
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // If there are even nodes, move fast one more step
    if (fast->next->next == head) {
        fast = fast->next;
    }
    
    // Set the head of second half
    *secondHead = slow->next;
    
    // Make first half circular
    slow->next = head;
    
    // Make second half circular
    fast->next = *secondHead;
    
    return head;
}

void printCircularList(Node head) {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    
    Node current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

Node createCircularList(int arr[], int n) {
    if (n == 0) return NULL;
    
    Node head = getNewNode(arr[0]);
    Node current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = getNewNode(arr[i]);
        current = current->next;
    }
    
    // Make it circular
    current->next = head;
    
    return head;
}

int main() {
    // Create a circular linked list: 1->2->3->4->5->6->1...
    int arr[] = {1, 2, 3, 4, 5, 6};
    Node head = createCircularList(arr, 6);
    
    cout << "Original circular list: ";
    printCircularList(head);
    
    Node secondHead = NULL;
    head = splitCircularList(head, &secondHead);
    
    cout << "First half: ";
    printCircularList(head);
    
    cout << "Second half: ";
    printCircularList(secondHead);
    
    // Test with odd number of nodes
    cout << "\n--- Testing with odd number of nodes ---" << endl;
    int arr2[] = {1, 2, 3, 4, 5};
    Node head2 = createCircularList(arr2, 5);
    
    cout << "Original circular list: ";
    printCircularList(head2);
    
    Node secondHead2 = NULL;
    head2 = splitCircularList(head2, &secondHead2);
    
    cout << "First half: ";
    printCircularList(head2);
    
    cout << "Second half: ";
    printCircularList(secondHead2);
    
    return 0;
}
