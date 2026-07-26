class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a < b;
        });
        int n = nums.size();
       
        int num1 = nums[0];
        int num2 = nums[1];
        int max_val  = INT_MIN;   
        for(int i=2;i<n;i++){
            max_val = max(max_val,num1*num2*nums[i]);
        }
        int num_1 = nums[n-1];
        int num_2 = nums[n-2];
        int num_3 = nums[n-3];
        return  max(max_val,num_2*num_1*num_3); 
    }
};