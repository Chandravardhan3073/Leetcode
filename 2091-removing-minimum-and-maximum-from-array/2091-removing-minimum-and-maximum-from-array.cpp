class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx,maxIdx,minVal = INT_MAX,maxVal = INT_MIN,n = nums.size() ;
        if(n == 1){
            return 1;
        }
        for(int i =0;i<n;i++){
            if(nums[i] < minVal){
                minVal = nums[i];
                minIdx = i;
            }
            if(nums[i] > maxVal){
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        int start = max(maxIdx +1,minIdx+1);
        int end = max(n - maxIdx,n-minIdx);
        int both = min(minIdx+1 + n-maxIdx,maxIdx+1+n-minIdx);
        
        return min({start,end,both});
    }
};