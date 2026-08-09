class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),[](int a,int b){
            return a > b;
        });
        sort(discounts.begin(),discounts.end(),[](int a ,int b){
            return a > b;
        });
        int i = 0,j = 0,idx;
        double ans = 0;
        while(i<prices.size() && j < discounts.size()){
            ans += (prices[i] * (100 - discounts[j])) / 100.0 ;
            
            i++;j++;
        }
        for(int id = i;i<prices.size();i++){
            ans += prices[i];
        }
        return ans;
    }
};