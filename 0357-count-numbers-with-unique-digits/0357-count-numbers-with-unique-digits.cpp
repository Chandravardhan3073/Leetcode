class Solution {
public:
    vector<int> ReturnVec(vector<int>& dp) {
        int n = dp.size();
        dp[1] = 10;
        for (int i = 2; i <n; i++) {
            int sum = 9;
            int num = 9;
            int idx = i;
            while (idx > 1) {
                sum = sum * num;
                num--;
                idx--;
            }
            dp[i] = dp[i - 1] + sum;
        }
        return dp;
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        if(n==0){
            return dp[0];
        }
        ReturnVec(dp);

        return dp[n];
    }
};