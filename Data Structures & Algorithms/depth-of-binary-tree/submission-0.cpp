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
    int maxi = 0;
    void dfs(TreeNode* root , int count){
        if(!root) return;
        if(!root->left && !root->right){
            count++;
            maxi = max(maxi , count);
            return;
        }
        count++;
        dfs(root->left,count);
        dfs(root->right,count);
    }
    int maxDepth(TreeNode* root) {
        dfs(root , 0);
        return maxi;
    }
};
