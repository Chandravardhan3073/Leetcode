class Solution {
public:
    string smallestPalindrome(string s) {
            string t ;
            for(int i =0;i<s.size()/2;i++){
                t.push_back(s[i]);
            }
            sort(t.begin(),t.end());
            
            string m = t;
            reverse(m.begin(),m.end());
            return (s.size() % 2 == 0) ? t+m : t+s[s.size()/2] +m ;
    }
};
//middle character is the one with an odd frequency,
//take the left part ? sort it reverse it add it  