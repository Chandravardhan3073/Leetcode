class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int dp_0 = nums[0];
        int dp_1 = max(nums[1], nums[0]);
        if(n == 2){
            return dp_1;
        }
        int dp_i = 0;
        for (int i = 2; i <= n-1; i++) {
            dp_i = max(dp_0 + nums[i], dp_1);
            dp_0 = dp_1;
            dp_1 = dp_i;
        }
        return dp_i;
    }
};

 