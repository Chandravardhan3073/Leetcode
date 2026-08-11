class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = nums[0],n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i =1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                sum += nums[i];
            }else{
                break;
            }
        } 
        while(true){
            if(mp.find(sum) != mp.end()){
                sum++;
            }else{
                return sum;
            }
        }
        return sum;
    }
};