class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for(char c : s){
            freq[c - 'a']++;
        }
        string t;
        for(char c : order){
            while(freq[c - 'a'] >0){
                t += c;
                freq[c - 'a']--;
            }
        }   

        for(char c : s){
            while(freq[c - 'a'] > 0){
                t += c;
                freq[c -'a']--;
            }
        }

 

        return t;
    }
};
//string count , char 
//FOR THE FIRST APPROACH :
// if s has more than 2 same char then we just add once and change that freq to 0 so all the same characters are not added twice 
