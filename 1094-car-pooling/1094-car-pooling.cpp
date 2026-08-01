class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> d(1001,0);
        int curr = 0,max_cap = 0;
        int max2 = 0;
        for(int i=0;i<trips.size();i++){
            d[trips[i][1]] += trips[i][0];
            d[trips[i][2]] -= trips[i][0]; 
            max2 = max(max2,trips[i][2]);
        }

        for(int i =0;i<=max2;i++){
            curr += d[i];
            max_cap = max(max_cap,curr);
        }
        return (max_cap <= capacity) ? true: false;
    }
};

//[from,to)