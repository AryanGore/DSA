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
    int maxCount = INT_MIN;
    void calcDepth(TreeNode* root , int count){
        if(!root){
           maxCount = max(maxCount , count);
           return;
        }

        calcDepth(root->left , count+1);
        calcDepth(root->right, count+1);

    }
    int maxDepth(TreeNode* root) {
        int count = 0;
        calcDepth(root, count);
        return maxCount;

    }
};
