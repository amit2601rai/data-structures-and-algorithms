int largestSumHelper(node root, int &maxSum, node &result){
    if(!root) return 0;
    int leftSum = largestSum(root->left, maxSum, result);
    int rightSum = largestSum(root->right, maxSum, result);
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
