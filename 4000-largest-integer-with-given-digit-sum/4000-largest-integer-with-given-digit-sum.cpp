class Solution {
public:
    string s;
    int dp[20][200];
    string ans;
    bool dfs(string& s, int pos, int sum, int tight, int S, string& currStr) {
        if (pos == s.size()) {
            if (sum == S) {
                ans = currStr;
                return true;
            } else {
                return false;
            }
        }
        if (!tight && dp[pos][sum] != -1) {
            return dp[pos][sum];
        }
        int limit = tight ? s[pos] - '0' : 9;
        long long ans = 0;
        for (int digit = limit; digit >= 0; digit--) {
            if (digit + sum > S)
                continue;
            currStr.push_back(digit + '0');
            if (dfs(s, pos + 1, sum + digit, tight && (limit == digit), S,currStr)) {
                return true;
            }
            currStr.pop_back();
        }
        if (!tight)
            dp[pos][sum] = 0;

        return false;
    }
    int largestInteger(int n, int S) {

        int num = pow(10, n) - 1;
        if (9 * n < S)
            return -1;
        s = to_string(num);
        memset(dp, -1, sizeof(dp));
        dfs(s, 0, 0, true, S, ans);
        return stoi(ans);
    }
};