class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        int n = s.size();
        string t;
        string m;
        for(int i =0;i<n;i++){
            freq[s[i]- 'a']++;
        }
        for(int i = 0;i<26;i++){
            t.append(freq[i]/2, char(i + 'a'));
        }
        for(int i=t.size()-1;i>=0;i--){
            m.push_back(t[i]);
        }
        return (n % 2 == 0) ? t+m: t+s[n/2]+m;
    }
};