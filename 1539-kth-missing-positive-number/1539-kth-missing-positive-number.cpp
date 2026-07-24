class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int end = arr[arr.size()-1];
        int cnt = 0;
        for(int i=1;i<=end+k;i++){
            if(binary_search(arr.begin(),arr.end(), i)){
                continue;
            }else{
                cnt++;
                if(cnt == k){
                    return i;
                }
            }
        }
        return -1;
    }
};