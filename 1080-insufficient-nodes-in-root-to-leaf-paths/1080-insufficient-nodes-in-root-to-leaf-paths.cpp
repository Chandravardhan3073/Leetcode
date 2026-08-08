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
    TreeNode* dfs(TreeNode* root, int limit,int Sum){
        if(root == NULL) return NULL;
        Sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(Sum < limit){
                return NULL;
            }else{
                return root;
            }
        }
        root->left = dfs(root->left,limit,Sum);
        root->right = dfs(root->right,limit,Sum);
     
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        return  root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root,limit,0);
    }
};