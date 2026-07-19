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
    int dfs(TreeNode* root,int &cnt){
        if(root == NULL){
            return 0;
        }
        int lf = dfs(root->left,cnt);
        int rf = dfs(root->right,cnt);
        int  max_i = max(lf,rf);
        if(root->val >= max_i){
            cnt++;
        }
        return max(root->val,max_i);
    }
    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        dfs(root,cnt);
        return cnt;
    }
};