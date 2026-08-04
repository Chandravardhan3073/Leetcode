class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size();
        int st = nums[0],e = nums[n-1];
        int i = 0,j=nums[0];
        while(i <n){
            if(nums[i] != j){
                ans.push_back(j);
                j++;
            }else if(nums[i] == j){
                i++;
                j++;
            }
        }
        return ans;
    }
};