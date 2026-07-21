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
    void dfs(TreeNode* root,vector<string>& s){
        if(root == NULL){
            s.push_back("N");
            return;
        }
        s.push_back(to_string(root->val));
        dfs(root->left,s);
        dfs(root->right,s);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> v1,v2;
        dfs(p,v1);
        dfs(q,v2);

        return v1 == v2;
    }
};