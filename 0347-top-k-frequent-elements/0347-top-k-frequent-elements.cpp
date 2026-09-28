class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;

        for(auto &it : mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        int i = 0;
        while(i<k){
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return ans;
    }
};
//k is the elementsin the vector , i solved using the bucket sort 
// for optimised version use priority queue 
