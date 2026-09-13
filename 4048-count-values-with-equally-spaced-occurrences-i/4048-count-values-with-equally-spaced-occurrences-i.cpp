class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int cnt  = 0;
        for(auto x : mp){
            if(x.second == 3){//3 freq
                vector<int> v;
                for(int j = 0;j < nums.size();j++){
                    if(nums[j] == x.first){
                        v.push_back(j);
                    }
                }
                if(v[2] - v[1] == v[1] - v[0]){
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};