int largestBSTinBTUtil(node root,int &maxValue,int &minValue,int &maxNodes,node &largestBST){
    if(!root)return 0;
    bool isBST = true;
    int curMinVal, curMaxVal, totalNodes;
    int leftNodes = largestBSTinBTUtil(root->left, maxValue, minValue, maxNodes, largestBST);
    int curMinVal = (leftNodes == 0)  ?  root->data : minVal;
    if(leftNodes == -1 || ((leftNodes != 0) && root->data <= maxVal)) isBST = false;
    int rightNodes = largestBSTinBTUtile(root->right, maxVal, minVal, maxNodes, largestBST);
    int curMaxVal = (rightNodes == 0) ? root->data : maxVal;
    if(rigthNodes == -1 || ((rightNodes != 0) && root->data >= minVal)) isBST = false;
    if(isBST){
        minVal =  curMinVal;
        maxVal = curMaxVal;
        totalNodes = leftNodes + rightNodes + 1;
        if(totalNodes > maxNodes){
            largestBST = root;
            maxNodes = totalNodes;
        }
        return totalNodes;
    }
    return -1;
}

node largestBSTinBT(node root){
    //For a particular subtree root at let's say A, minValue is minimum value in that subtree and maxValue is maximum value in that subtree
    int minValue = INT_MAX, maxValue = INT_MIN, maxNodes;
    maxNodes = INT_MIN;
    node largestBST;
    largestBSTinBTUtil(root, maxValue, minValue, maxNodes, largestBST);
    return largestBST;
}
