class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int maxi = nums[0];
        for(int i = 0;i<nums.size();i++){
            if(maxi < nums[i]){
                maxi = nums[i];
            }
            prefixGcd.push_back(gcd(maxi,nums[i]));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i = 0,j = prefixGcd.size()-1;
        long long  sum = 0;
        while(i<j){
            sum += gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};