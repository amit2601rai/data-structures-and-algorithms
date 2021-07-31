#include "Header.cpp"
#include "Node.cpp"
#include "InsertionSinglyLinkedList.cpp"
#include "InsertionDoublyLinkedList.cpp"
#include "InsertionCircularLinkedList.cpp"
#include "PrintList.cpp"
#include "AlternateSpilitOfLinkedList.cpp"
#include "DLLToBST.cpp"
#include "SortedLinkedListToBST.cpp"
#include "DeleteAlternateNode.cpp"
#include "DeleteNNodesAfterMNodes.cpp"
#include "MergeAlternateLinkedList.cpp"
#include "Sort01.cpp"
#include "ReverseDoublyLinkedList.cpp"
#include "Reverse.cpp"
#include "SortedInsertInCircularList.cpp"
#include "SpilitCircularInTwoHalves.cpp"
#include "StackWithMiddleOperation.cpp"
#include "MergeSortOnLinkedList.cpp"
#include "RotateLinkedList.cpp"
#include "PairwiseSwap.cpp"
#include "AddTwoLinkedList.cpp"
#include "AddTwoLinkedListUsingRecursion.cpp"

int main(){
    Node head1 = NULL, head2 = NULL;
    int n,m,x;
    cin>>n>>m;
    while(n--){
        cin>>x;
        head1 = insertatend(head1,x);
    }
    while(m--){
        cin>>x;
        head2 = insertatend(head2,x);
    }
   // Node result = add_lists(head1, head2);
    printSinglyLinkedList(reverse(add_list_rec(reverse(head1),reverse(head2),0)));
return 0;
}
