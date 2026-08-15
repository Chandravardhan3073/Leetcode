class Solution {
public:
    void ReturnVec(vector<int>& dp) {
        int n = dp.size();
        dp[1] = 10;
        vector<int> w(9,0);
        w[0] = 9;
        int num = 9;
        for (int i = 2; i <n; i++) {
            w[i-1] = w[i-2] *  num;
            num--;
            dp[i] = dp[i - 1] + w[i-1];
            cout << w[i-1] << " ";
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