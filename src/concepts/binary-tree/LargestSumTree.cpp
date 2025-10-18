#include "BinaryTreeCommon.h"

int largestSumHelper(node root, int &maxSum, node &result){
    if(!root) return 0;
    int leftSum = largestSumHelper(root->left, maxSum, result);
    int rightSum = largestSumHelper(root->right, maxSum, result);
    int total = leftSum + rightSum + root->data;
    if(total > maxSum){
        maxSum = total;
        result = root;
    }
    return total;
}

node largestSum(node root){
    node result = NULL;
    int maxSum = INT_MIN;
    largestSumHelper(root, maxSum, result);
    return result;
}

int main() {
    node root = setupTree();
    node result = largestSum(root);
    
    if(result) {
        cout << "Root of subtree with largest sum: " << result->data << endl;
    } else {
        cout << "No subtree found" << endl;
    }
    
    return 0;
}
