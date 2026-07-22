class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int idx){
        if(idx <= 0){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int inc = solve(nums,dp,idx-2) + nums[idx-1];
        int exc = solve(nums,dp,idx -1);
        return dp[idx] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        int ans = solve(nums,dp,n);
        return ans;
    }
};