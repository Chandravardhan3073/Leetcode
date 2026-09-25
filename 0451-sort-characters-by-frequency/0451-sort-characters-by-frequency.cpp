class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        vector<vector<char>> buckets(s.size()+1);
        string ans ="";
        for(auto &it:mp){
            buckets[it.second].push_back(it.first);
        }
        for(int i=s.size();i>=1;i--){
            for(char c:buckets[i]){
                ans += string(i,c);
            }
        }
        return ans;
    }
};