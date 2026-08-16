class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int maxVal = INT_MIN;
        int NegMax = INT_MAX;
        int negCnt = 0;
        long long  product = 1;
        int zeroCnt = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] < 0){
                negCnt ++;
                NegMax = min(NegMax, abs(nums[i]) );
            }
            maxVal = max(maxVal,nums[i]);

            if(nums[i] == 0){
                zeroCnt ++;
            }
            if(nums[i] != 0){
                product *= nums[i];
            }
        }
        if(negCnt == 1 && nums.size() == 1){
            return nums[0];
        }
        if(maxVal == 0 && negCnt == 1){ //[-5,0,0]
            return 0;
        }

        if(zeroCnt == nums.size()){
            return 0;// all zeroes
        }

        if(negCnt == 0){
            return product;// all positives
        }

        if(negCnt % 2 == 1){//if odd neg no then neg   make it pos
            return -(product / NegMax);
        }else{//even dont include zero 
            return product;
        }
    }
};