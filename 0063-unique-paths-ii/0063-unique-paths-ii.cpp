class Solution {
public:
    int f(int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(m > obstacleGrid.size()-1 || n>obstacleGrid[0].size()-1){
            return 0;//outside grid
        }
        if(obstacleGrid[m][n] == 1){
            return 0;//obstucle
        }
        if(m == obstacleGrid.size()-1 &&  n== obstacleGrid[0].size()-1){
            return 1;//goal
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int right = f(m,n+1,obstacleGrid,dp);
        int down = f(m+1,n,obstacleGrid,dp);
        return dp[m][n] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m =obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return f(0,0,obstacleGrid,dp);
    }
};

// the order matter 