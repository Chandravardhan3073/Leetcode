class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mp;
        
        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
        }
        int odd_freq = 0;
        for(const auto&[key,val] : mp){
            if(val % 2 == 1){
                odd_freq++;
            }
        }
        if(s.size() % 2 == 0 && odd_freq == 0){
            return s.size();    
        }
        if(s.size() % 2 == 1 && odd_freq == 1){
            return s.size();
        }
        return s.size() - (odd_freq - 1);
    }
};