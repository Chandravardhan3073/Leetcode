class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto & it: mp){
            buckets[it.second].push_back(it.first);
        }
        
        vector<int> v;
        for (int i = buckets.size()-1;i>=1;i--) {
            for (int x : buckets[i]) {
                if(v.size() == k){
                    break;
                }
                v.push_back(x);
            }
        }
        return v;
    }
};