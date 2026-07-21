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
    void dfs(TreeNode* root,int parent,bool &codn,int targetSum){
        if(!root){
            return;
        }
         parent += root->val;
        if(!root->left && !root->right){
            if(parent== targetSum){
                codn = true;
            }
        }
        dfs(root->left,parent,codn,targetSum);
        dfs(root->right,parent,codn,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool codn = false;
        dfs(root,0,codn,targetSum); 
        return codn;
    }
};