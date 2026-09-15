class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long  leftSum = 0, rightSum = 0;
        int n = nums.size(), i = 0, j = n / 2;
        while (i < n / 2 && j < n) {
            leftSum += nums[i];
            rightSum += nums[j];
            i++;
            j++;
        }
        int cnt = 0;
        i = 0, j = n / 2;
        for (int k = 0; k < n; k++) {
            leftSum = leftSum - nums[i] + nums[j];
            rightSum = rightSum - nums[j] + nums[i];
            if (leftSum > rightSum) {
                cnt++;
            }
            i = (i + 1) % n;
            j = (j + 1) % n;
        }

        return cnt;
    }
};