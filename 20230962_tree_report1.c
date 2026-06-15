#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int data;                      
    struct TreeNode* left;        
    struct TreeNode* right;       
} TreeNode;
int getSum(TreeNode* node) {
    if (node == NULL)
        return 0;

    return node->data +
        getSum(node->left) +
        getSum(node->right);
}


int getMax(TreeNode* node) {
    if (node == NULL)
        return -1;

    int leftMax = getMax(node->left);
    int rightMax = getMax(node->right);

    int max = node->data;

    if (leftMax > max)
        max = leftMax;

    if (rightMax > max)
        max = rightMax;

    return max;
}

void searchRange(TreeNode* node, int min, int max) {
    if (node == NULL)
        return;

    if (node->data >= min && node->data <= max)
        printf("%d ", node->data);

    searchRange(node->left, min, max);
    searchRange(node->right, min, max);
}