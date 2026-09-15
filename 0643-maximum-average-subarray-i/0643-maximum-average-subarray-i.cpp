class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avgVal = 0,sum = 0 ;
        double maxVal = 0;
        for(int i =0;i<k;i++){
            sum += nums[i];
        }
        avgVal = sum /(double)k;
        maxVal = avgVal;
        int st = 0,end = k;
        for(int i = k;i<nums.size();i++){
            sum = sum - nums[st] + nums[end];
            avgVal = sum / (double) k;
            maxVal = max(maxVal,avgVal);
            st++;
            end++;
        }
        return maxVal;
    }
};