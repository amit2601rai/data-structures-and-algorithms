#include "Header.cpp"
#include "Node.cpp"
#include "Insert.cpp"
#include "SumOfNumbersFormedFromRootToLeaf.cpp"
#include "NodesWithoutSiblings.cpp"
#include "AddAllGreaterElementInBinaryTree.cpp"
#include "Inorder.cpp"
#include "CheckLeavesAtSameLevel.cpp"
#include "SortedArrayToBST.cpp"
#include "K-thSmallestElementInBST.cpp"
#include "FirstLargerElement.cpp"
#include "Delete.cpp"
#include "IsPairSum.cpp"

int main(){
    int T;
    cin>>T;
    while(T--){
	node root = NULL;
    int n,x;
    cin>>n;
	while(n--){
      cin>>x;
      root=insert(root,x);
	}
	inorder(root);
	cout<<endl;
	int SUM;
	cin>>SUM;
	if(isPairSum(root, SUM)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;}
	return 0;
}
