//Binary Tree
#include "Header.cpp"
#include "Node.cpp"
#include "BinaryTreeConstruction.cpp"
#include "ZigZagTraversal.cpp"
#include "BTtoDLL.cpp"
#include "DistanceBetweenTwoKeysInBinaryTree.cpp"
#include "DeepestOddLevelLeaf.cpp"
#include "DeepestLeftLeaf.cpp"
#include "PostOrderTraversal.cpp"
#include "InOrderTraversal.cpp"
#include "PreOrderTraversal.cpp"
#include "PreOrderMorrisTraversal.cpp"
#include "RemoveAllNodesNotInK-Path.cpp"
#include "LeftView.cpp"
#include "DifferenceBetweenOddEvenLevels.cpp"
#include "Height.cpp"
#include "Diameter.cpp"

int main(){
    node root=NULL;
    root=construction_BT();
    int ans = INT_MIN;
    diameterOpt(root,ans);
    cout<<ans<<endl;
    cout<<diameter(root)<<endl;
return 0;
}
