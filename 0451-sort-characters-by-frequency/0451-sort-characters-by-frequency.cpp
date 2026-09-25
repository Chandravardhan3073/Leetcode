class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0);

        for (char c : s) {
            freq[c]++;
        }

        vector<string> buckets(s.size() + 1);

        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                buckets[freq[i]].push_back((char)i);
            }
        }

        string ans;

        for (int i = s.size(); i >= 1; i--) {
            for (char c : buckets[i]) {
                ans += string(i, c);
            }
        }

        return ans;
    }
};