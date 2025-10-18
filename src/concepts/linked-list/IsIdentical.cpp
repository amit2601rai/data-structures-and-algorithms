#include "LinkedListCommon.h"

bool identical(struct node* head1, struct node* head2){
	if(head1!=NULL && head2!=NULL)
		return identical(head1->next,head2->next)&&(head1->data==head2->data);
	else if(head1==NULL && head2==NULL)
		return true;
	return false;
}

Node createSecondList() {
    Node head = getNewNode(1);
    head->next = getNewNode(2);
    head->next->next = getNewNode(3);
    head->next->next->next = getNewNode(4);
    head->next->next->next->next = getNewNode(5);
    return head;
}

Node createDifferentList() {
    Node head = getNewNode(1);
    head->next = getNewNode(2);
    head->next->next = getNewNode(7); // Different from setupList
    return head;
}

int main() {
    Node list1 = setupList();
    Node list2 = createSecondList();
    Node list3 = createDifferentList();
    
    cout << "List 1: ";
    printList(list1);
    
    cout << "List 2: ";
    printList(list2);
    
    cout << "List 3: ";
    printList(list3);
    
    bool result = identical(list1, list2);
    cout << "List 1 and List 2 identical? " << (result ? "Yes" : "No") << endl;
    
    result = identical(list1, list3);
    cout << "List 1 and List 3 identical? " << (result ? "Yes" : "No") << endl;
    
    return 0;
}
