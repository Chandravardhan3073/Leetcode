class Solution {
public:
    long long nextN(int N) {
        long long sum = 0;
        while (N > 0) {
            long long d = N % 10;
            sum +=  d *d;
            N /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        long long slow = n;
        long long fast = n;
        while (true) {
            slow = nextN(slow);
            fast = nextN(nextN(fast));
            if(fast == 1){//or slow == fast 
                return true;
            }
            if(slow == fast){
                return false;
            }
        }
        return true;
    }
};