class Solution {
public:
    int maxDepth(string s) {
        int i = 0,ans = 0,cnt = 0;
        while(i < s.size()){
            if(s[i] == '('){
                cnt = cnt +1;
            }
            ans = max(ans,cnt);
            if(s[i] == ')'){
                cnt--;
            }
            i++;
        }
        return ans;
    }
};