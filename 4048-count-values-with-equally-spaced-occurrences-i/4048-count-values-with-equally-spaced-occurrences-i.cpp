class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int cnt = 0;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto x:mp){
            if(x.second.size() == 3){
                if(x.second[1] - x.second[0] == x.second[2] - x.second[1]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};