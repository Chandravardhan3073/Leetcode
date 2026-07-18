class Solution {
public:
    int solve(vector<int>& cost,int i,vector<int> &dp){
        if(i == 0 || i==1){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int left = solve(cost,i-1,dp) + cost[i-1];
        
        int right = solve(cost,i-2,dp) + cost[i-2];
        
        return dp[i] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() +1,-1);
        int ans = solve(cost,cost.size(),dp);
        return ans;
    }
};