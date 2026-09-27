class Solution {
public:
    int f(int n ,int idx, int prev, vector<int>& nums,vector<vector<int>>& dp) {
        if(idx == n){
            return 0;
        }
        int take = 0;
        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }
        if (prev ==  n ||nums[idx] > nums[prev]) {
            take = 1 + f(n,idx + 1,idx, nums,dp);
        }
        int skip= f(n,idx + 1, prev, nums,dp);

        return dp[idx][prev] = max(take , skip);
    }
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n,0,n,nums,dp); 
    }
};