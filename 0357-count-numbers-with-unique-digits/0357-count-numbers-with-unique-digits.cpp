class Solution {
public:
    vector<int> dp;
    Solution() {
        dp.resize(9);
        int n = dp.size();
        dp[0] = 1;
        dp[1] = 10;
        int w = 9;
        int num = 9;
        for (int i = 2; i < n; i++) {
            w *= num;
            num--;
            dp[i] = dp[i - 1] + w;
        }
    }
    int countNumbersWithUniqueDigits(int n) { 
        return dp[n]; 
    }
};