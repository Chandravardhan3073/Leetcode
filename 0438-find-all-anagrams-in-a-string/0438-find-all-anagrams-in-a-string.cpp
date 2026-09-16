class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sfreq(26, 0);
        vector<int> pfreq(26, 0);
        vector<int> a;
        if(p.size() > s.size()){
            return a;
        }
        for (int i = 0; i < p.size(); i++) {
            sfreq[s[i] - 'a']++;
            pfreq[p[i] - 'a']++;
        }

        bool isTrue = true;

        for(int i=0;i<26;i++){
            if(sfreq[i] != pfreq[i]){
                isTrue = false;
                break;
            }
        }

        if(isTrue){
            a.push_back(0);
        }
        for (int i = 1; i <= s.size() - p.size(); i++) {
            sfreq[s[i - 1] - 'a']--;
            sfreq[s[i+p.size()-1] - 'a']++;
            isTrue = true;
            for(int i=0;i<26;i++){
                if(sfreq[i] != pfreq[i]){
                    isTrue = false;
                    break;
                }
            }
            if(isTrue){
                a.push_back(i);
            }
        }
        return a;
    }
};