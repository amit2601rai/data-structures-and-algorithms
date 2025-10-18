#include "BinaryTreeCommon.h"

int func(int level){
    return (level%2 == 0 ? 1 : -1);
}

int diffOddEvenUtil(node root,int level){
	if(!root)return 0;
	return func(level)*(root->data)+diffOddEvenUtil(root->left,level+1)+diffOddEvenUtil(root->right,level+1);
}

int diffOddEven(node root){
    int diff = diffOddEvenUtil(root,0);
    return abs(diff);
}

int main() {
    node root = setupTree();
    cout << "Difference between sum of odd and even levels: " << diffOddEven(root) << endl;
    return 0;
}
