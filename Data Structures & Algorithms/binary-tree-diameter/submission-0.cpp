/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDiameter = INT_MIN;
    int calcDiameter(TreeNode* root , int count){
        if(!root) return 0;
        count++;

        int leftCount = calcDiameter(root->left, 0);
        int rightCount = calcDiameter(root->right, 0);

        maxDiameter = max(maxDiameter, leftCount+rightCount);
        return count + max(leftCount , rightCount);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calcDiameter(root, 0);
        return maxDiameter;
    }
};
