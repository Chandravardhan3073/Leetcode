class Solution {
public:
    int solve(vector<int>& nums,int st,int end){
        int prev2 = 0;
        int prev = nums[st];
        for(int i =st+1;i<=end;i++){
            int curri = max(prev2 + nums[i],prev);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        int n = nums.size()-1;//index
        int case1 = solve(nums,0,n-1);
        int case2 = solve(nums,1,n);
        return max(case1,case2);
    }
};