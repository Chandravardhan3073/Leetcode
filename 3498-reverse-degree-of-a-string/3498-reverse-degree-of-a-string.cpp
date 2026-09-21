class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char ,int> mp;
        for(int i=1;i<=26;i++){
            mp['z' - i+1]= i;
        }
        int ans = 0;
        for(int i=0;i<s.size();i++){
            ans += mp[s[i]] * (i+1);
        }
        return ans;
    }
};