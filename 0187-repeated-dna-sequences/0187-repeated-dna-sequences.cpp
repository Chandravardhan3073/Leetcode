class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> v;
        unordered_map<string,int> mp;
        int i = 0;
        if(s.size() < 10){
            return v;
        }
        while(i<=s.size() -10){
    
            int j = 0;
            string str = "";
            while(j < 10){
                str += s[j + i];
                j ++;
            }
            mp[str]++;
            i++;
        }

        for(const auto&[key,value]: mp){
            if(value>1){
                v.push_back(key);
            }
        }
        return v;
    }
};