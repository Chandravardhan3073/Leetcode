class Solution {
public:
    long long countCommas(long long n) {
        long long lower = 1000,commas = 1,upper =  999999,ans = 0;
        if(lower>n) return 0;
        while(lower <= n){
            if(n>upper){
                ans += (upper- lower+1) * commas;
            }else{
                ans += (n-lower +1)*commas;
                break;
            }
            lower *= 1000;
            upper = lower * 1000 -1;
            commas++;
        }
        return ans;
    }
};