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
    pair<int,int> dfs(TreeNode* root,int &cnt,int Sum,int count){
        if(root == NULL){
            return {0,0};
        }
        pair<int,int> lf = dfs(root->left,cnt,Sum,count )  ;
        
        pair<int,int> rf = dfs(root->right,cnt,Sum ,count)  ;
        Sum = lf.first + rf.first +root->val  ;
        count = 1  + lf.second + rf.second;

        int avg = ( Sum ) / (count) ;
        if(avg == root->val){
            cnt++;
        }
        
        return {Sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        int Sum= 0;
        int count = 0;
        dfs(root,cnt,Sum ,count);
        return cnt;
    }
};