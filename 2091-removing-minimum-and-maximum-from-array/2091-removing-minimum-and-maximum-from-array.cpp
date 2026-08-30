class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0,maxIdx=0,n = nums.size() ;
        if(n == 1){
            return 1;
        }
        for(int i =0;i<n;i++){
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }
        int start = max(maxIdx +1,minIdx+1);
        int end = max(n - maxIdx,n-minIdx);
        int both = min(minIdx+1 + n-maxIdx,maxIdx+1+n-minIdx);
        
        return min({start,end,both});
    }
};