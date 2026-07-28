class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        int n = s.size();
        string t;
        
        for(int i =0;i<n;i++){
            freq[s[i]- 'a']++;
        }
        string mid ;
        for(int i = 0;i<26;i++){
            t.append(freq[i]/2, char(i + 'a'));
            if(freq[i] % 2 == 1){
                mid = char(i+'a');
            }
        }
        string m = t;
        reverse(m.begin(),m.end());
        return  t+ mid + m;
    }
};
//middle character is the one with an odd frequency,