class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i =0; i<= nums.size()-k;i++){
            unordered_set<int> st;
            for(int j=i;j<k+i;j++){
                st.insert(nums[j]);
            }

            for(int x : st ){
                mp[x]++;
            }
        }
        int maxVal = INT_MIN;
        for(const auto&[key,val]:mp){
            if(val == 1){
                maxVal = max(maxVal,key);
            }
        }
        return maxVal == INT_MIN ?-1:maxVal;
    }
};