class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a < b;
        });
        int n = nums.size();
        int num1 = nums[0];
        int num2 = nums[1];
        int num_1 = nums[n-1];//max number 
        int num_2 = nums[n-2];
        int num_3 = nums[n-3];
        return  max(num_1*num2*num1,num_2*num_1*num_3); 
    }
};

//max(maxval*2 small values , 3 max vales from end after sort )