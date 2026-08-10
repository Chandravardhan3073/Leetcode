class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0 ;i<n ;i++){
            int total = (n-i) * (i +1);
            if(total % 2 == 0){
                sum += (total/2) * arr[i];
            }else{
                sum += (total/2 +1) * arr[i];
            }
        }
        return sum;
    }
}; // calculate how many times the idx appears at start and end n-idx * idx+1         then for odd divide by 2 and add 1 for even divide by 2 and Multiply the number  with the value at idx and use a sum variabale to track the sum