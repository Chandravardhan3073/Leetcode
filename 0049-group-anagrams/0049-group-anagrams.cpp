class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
       
        for(string s : strs){
            vector<int> freq(26,0);
            for(char c:s){
                freq[c - 'a']++ ;
            }
            string temp="";
            for(int i =0;i<freq.size();i++){
                temp += freq[i];
            }
            mp[temp].push_back(s);
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};