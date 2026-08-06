class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = n;
        while (true) {
            int pro = 1;
            int N=i;
            while ( N> 0) {
                pro *= N % 10;
                N /= 10;
            }
            if (pro % t == 0) {
                return i;
            }
            i++;
        }
        return -1;
    }
};