class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        int i = 1;
        while(i<=n){
            int org = i;
            if(i>=1000){
                while(i>=1000){
                    i = i/1000;
                    count++;
                }
                i = org;
            }
            i++;
        }
        return count;
    }
};