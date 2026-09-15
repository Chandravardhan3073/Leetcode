class Solution {
public:
    struct Info {
        int count = 0;
        int prev = -1;
        int diff = -1;
        bool valid = true;
    };
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, Info> mp;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (mp[x].count == 0) {
                mp[x].count++;
                mp[x].prev = i;
            } else if (mp[x].count == 1) {
                mp[x].diff = i - mp[x].prev;
                mp[x].prev = i;
                mp[x].count++;
            } else {
                if (mp[x].valid != false) {// if reached false already then no need to check
                    int newDiff = i - mp[x].prev;
                    if (newDiff != mp[x].diff) {
                        mp[x].valid = false;
                    }
                }
                mp[x].count++;
                mp[x].prev = i;
            }
        }
        int cnt = 0;
        for(auto x : mp){
            if(x.second.count >= 3 && x.second.valid == true){
                cnt++;
            }
        }
        return cnt;
    }
};