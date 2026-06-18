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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>finalans;
        vector<int>ans;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            ans.clear();
            int i = q.size();
            while(i--){
                TreeNode* front = q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                q.pop();
                ans.push_back(front->val);
            }

            finalans.push_back(ans);

        }

        return finalans;

    }
};
