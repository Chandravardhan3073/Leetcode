class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater());
        sort(discounts.begin(),discounts.end(),greater());
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