class Solution {
public:
    int dp[20][200];
    string s ;
    long long dfs(string &s,int pos,int cnt,int tight){
        if(pos == s.size()){
            return  cnt; 
        }
        if(!tight && dp[pos][cnt] != -1 ){
            return dp[pos][cnt];
        }
        long long res = 0;

        int limit = tight?s[pos] - '0':9;

        for(int digit = 0;digit<=limit;digit++){
            res += dfs(s,pos+1,cnt + ((digit == 1) ? 1 : 0),tight && (limit == digit));
        }
        return dp[pos][cnt] = res;
    }

    int countDigitOne(int n) {
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return dfs(s,0,0,true);
    }
};