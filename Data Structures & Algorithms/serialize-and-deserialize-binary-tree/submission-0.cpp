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

class Codec {
    void serializehelper(TreeNode* root, string& result){
        if(!root){
            result += "N,";
            return;
        }
        result += to_string(root->val) + ",";
        serializehelper(root->left, result);
        serializehelper(root->right, result);
    }

    TreeNode* deserializehelper(vector<string>&nodes, int& idx){
        if(nodes[idx] == "N"){
            return nullptr;
        }
        int val = stoi(nodes[idx]);
        TreeNode* root = new TreeNode(val);
        idx++;
        root->left = deserializehelper(nodes, idx);
        idx++;
        root->right = deserializehelper(nodes, idx);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        serializehelper(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodes;
        string temp = "";
        for(auto c: data){
            if(c == ','){
                nodes.push_back(temp);
                temp = "";
            }else{
                temp += c;
            }
        }
        int idx = 0;
        return deserializehelper(nodes, idx);
    }
};
