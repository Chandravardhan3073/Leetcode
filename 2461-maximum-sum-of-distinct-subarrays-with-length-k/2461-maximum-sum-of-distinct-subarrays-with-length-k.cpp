class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, n = nums.size() ;
        long long max_Sum = 0;
        long long sum = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            sum += nums[i];
            mp[nums[i]]++;
        }
        if(mp.size() == k){
            max_Sum = sum;
        }

        for(int i = k;i<n;i++){
            sum -= nums[i-k];
            mp[nums[i-k]]--;
            
            if(mp[nums[i-k]] == 0){
                mp.erase(nums[i-k]);
            }

            sum += nums[i];
            mp[nums[i]]++;
            if(mp.size() == k){
                max_Sum = max(max_Sum,sum);
            }
        }
        
        return max_Sum;
    }
};