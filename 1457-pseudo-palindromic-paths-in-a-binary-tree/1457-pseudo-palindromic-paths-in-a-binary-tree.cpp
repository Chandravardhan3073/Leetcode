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
    bool isLeaf(TreeNode* root){
        if(root->right == NULL && root->left ==NULL){
            return true;
        }
        return false;
    }
    bool countFreq(vector<int>& freq){
        int cnt = 0;
        for(int i =0;i<freq.size();i++){
            if(freq[i] % 2 != 0){
                cnt++;
            }
        }
        return cnt == 0|| cnt == 1; // since the odd counts should equal to 0 or  1 only 
    }
    void dfs(TreeNode* root, int &cnt,vector<int>& freq){
        if(root == NULL){
            return ;
        }
        freq[root->val] ++;
        if(isLeaf(root) && countFreq(freq)){
            cnt++;
        }
        dfs(root->left,cnt,freq);
        dfs(root->right,cnt,freq);
        freq[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt =  0;
        string s = "";
        vector<int> freq(10,0);
        dfs(root,cnt,freq);
        return cnt;
    }
};

