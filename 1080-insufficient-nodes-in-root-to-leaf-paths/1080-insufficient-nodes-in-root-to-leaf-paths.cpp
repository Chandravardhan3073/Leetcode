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
        TreeNode* lf = dfs(root->left,limit,Sum);
        TreeNode* rf = dfs(root->right,limit,Sum);
        if(lf == NULL){
            root->left = NULL;
        }
        if(rf == NULL){
            root->right = NULL;
        }      
        if(lf == NULL && rf == NULL){
            return NULL;
        }
        return  root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root,limit,0);
    }
};