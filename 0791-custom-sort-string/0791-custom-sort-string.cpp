class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for(int i =0;i<s.size();i++){
            freq[s[i] - 'a']++;
        }

        string t ;
        for(char c : order){
            if(freq[c - 'a'] >= 1){
                t += string(freq[c - 'a'],c);
                freq[c - 'a'] = 0;
            }
        }
        
        for(char c : s){
            if(freq[c - 'a'] != 0){
                t+= string(freq[c - 'a'],c);
                freq[c - 'a'] = 0;
            }
        }

        return t;
    }
};
//string count , char 