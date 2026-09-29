class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> mp2;
        int i = 0,j = 0;
        while(i<s.size() && j <t.size()){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[j]){
                    return false;
                }
            }
            if(mp2.find(t[j]) != mp2.end()){
                if(mp2[t[j]] != s[i]){
                    return false;
                }
            }
            mp[s[i]] = t[j];
            mp2[t[j]] = s[i];
            i++;
            j++;
        }
        return true;
    }
};