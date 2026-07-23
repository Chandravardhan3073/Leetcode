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
    int dfs(TreeNode* root,int &max_length){
        if(root == NULL){
            return 0;
        }
        int lf = dfs(root->left,max_length);
        lf = (root->left != NULL && root->left->val == root->val) ? lf + 1 : 0;
        int rf = dfs(root->right,max_length);
        rf = (root->right != NULL && root->right->val == root->val) ? rf + 1 : 0;
        max_length = max(max_length ,lf + rf);
        return max(lf,rf);
    }
    int longestUnivaluePath(TreeNode* root) {
        int max_length = 0;
        int ans = dfs(root,max_length);
        return max_length;
    }
};