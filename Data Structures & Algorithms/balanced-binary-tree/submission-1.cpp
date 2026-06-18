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
    pair<int, bool> maxHeight(TreeNode* root){
        if(!root) return {0, true};

        pair<int,bool> left = maxHeight(root->left);
        pair<int, bool> right = maxHeight(root->right);

        if(!left.second || !right.second) return {-1, false};

        pair<int,bool> ans;
        ans.first = 1 + max(left.first, right.first);

        if(abs(left.first - right.first) <= 1) {
            ans.second = true;
            return ans;
        }

        ans.second = false;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        pair<int, bool> ans = maxHeight(root);
        return ans.second;
    }
};
