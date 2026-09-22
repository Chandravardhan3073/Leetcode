class Solution {
public:
    int solve(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int prev2 = 0;
        int prev = nums[0];
        int curri;

        for (int i = 1; i < nums.size(); i++) {
            curri = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curri; // for next i
        }
        return prev;
    }
    // house  robber 1
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        
        vector<int> temp1,temp2;

        for(int i=0;i<n;i++){
            if(i != 0){
                temp1.push_back(nums[i]);
            }
            if(i != n-1){
                temp2.push_back(nums[i]);
            }
        }
        int case1 = solve(temp1);
        int case2 = solve(temp2);

        return max(case1,case2);
    }
};