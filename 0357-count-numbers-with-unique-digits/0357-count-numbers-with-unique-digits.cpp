class Solution {
public:
    void ReturnVec(vector<int>& dp) {
        int n = dp.size();
        dp[1] = 10;
        int w = 9;
        int num = 9;
        for (int i = 2; i <n; i++) {
            w *= num;
            num--;
            dp[i] = dp[i-1] + w;
        }   
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(9,0);
        dp[0] = 1;
        if(n==0){
            return dp[0];
        }
        ReturnVec(dp);

        return dp[n];
    }
};