class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int prev2 = nums[0];
        int curri ;

        int prev = max(nums[0],nums[1]);
        for(int i =2;i<nums.size();i++){
            curri = max(prev,prev2+nums[i]);
            prev2 = prev; 
            prev = curri;//for next i 
        }
        return prev;
    }
};