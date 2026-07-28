class Solution {
public:
    string smallestPalindrome(string s) {

        int n = s.size();
        if(n == 1) return s;
        map<char,int> mp;
        for(int i =0;i<n;i++){
            mp[s[i]]++;
        }
        string t;
        for(const auto&[key,val]:mp){
            t.append(val/2,key);
        }
        string m =t;
        reverse(m.begin(),m.end());
        return n%2 == 0 ?  t + m: t + s[n/2] + m;
    }
};