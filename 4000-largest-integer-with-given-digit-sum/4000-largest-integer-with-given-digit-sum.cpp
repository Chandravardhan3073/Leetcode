class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num >0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int largestInteger(int n, int s) {
        if(s == 0)return 0;
        if(n*9 < s)return -1;
        int Num = pow(10,n) -1;
        while (true) {
            int sum = digitSum(Num);
            if (sum == s)
                return Num;
            int diff = sum - s;
            Num -= diff;
        }

        return -1;
    }
};