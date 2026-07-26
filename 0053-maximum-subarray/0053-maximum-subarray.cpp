class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_Sum =  nums[0];
        int currSum = 0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            max_Sum = max(max_Sum,currSum); 
            
            if(currSum <0){
                currSum = 0;
            }
        }
        return max_Sum;
    }
};