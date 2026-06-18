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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        deque<TreeNode*>q;
        q.push_back(root);
        ans.push_back(root->val);

        while(!q.empty()){
            int i = q.size();
            while(i--){
                TreeNode* front = q.front();
                if(front->left) q.push_back(front->left);
                if(front->right) q.push_back(front->right);
                q.pop_front();
            }

            if(q.back()->val != ans.back()) ans.push_back(q.back()->val);

        }

        return ans;
    }
};
