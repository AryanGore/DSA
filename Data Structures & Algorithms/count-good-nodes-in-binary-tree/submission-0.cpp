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
    
    void getGoodNodes(TreeNode* root, int maxVal, int& count){
        if(!root) return;
        if(root->val >= maxVal) count++;
        // maxVal = max(maxVal, root->val);
        getGoodNodes(root->left, max(maxVal, root->val), count);
        getGoodNodes(root->right, max(maxVal, root->val), count);     
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        getGoodNodes(root, root->val, count);
        return count;
    }
};
