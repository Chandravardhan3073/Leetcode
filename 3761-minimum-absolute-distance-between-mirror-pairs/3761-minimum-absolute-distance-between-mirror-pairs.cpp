class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<string, int> mp;
        int minVal = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            string org = s;
            reverse(s.begin(), s.end());
            if (!s.empty() && s.front() == '0') {
                s = to_string(stoi(s));
                 
            }
            if (mp.find(org) != mp.end()) {
                minVal = min(minVal, abs(i - mp[org]));
            }
            mp[s] = i;
        }
        return minVal == INT_MAX ? -1 : minVal;
    }
};