class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int prev2 = 0;
        int prev = nums[0];
        int curri ;
        
        
        for(int i =1;i<nums.size();i++){
            curri = max(prev,prev2+nums[i]);
            prev2 = prev; 
            prev = curri;//for next i 
        }
        return prev;
    }
};