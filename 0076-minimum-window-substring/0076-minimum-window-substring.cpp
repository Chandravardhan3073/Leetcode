class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0,right = 0;
        vector<int> sfreq(128,0);
        vector<int> tfreq(128,0);
        if(t.size() > s.size()){
            return "";
        }
        int req = 0;
        for(int i =0;i<t.size();i++){
            tfreq[t[i]]++;
        }
        for(int i=0;i<128;i++){
            if(tfreq[i] != 0){
                req++;
            }
        }
        int matches = 0;
         
        int minLength = INT_MAX; 
        int start = 0;
        while(right < s.size()){
            sfreq[s[right]]++;
            
            if(sfreq[s[right]] == tfreq[s[right]]){
                matches++;
            }

            while(matches == req){
                int length =  right - left +1;
                if(length < minLength){
                    start = left;
                    minLength = length;
                }
                if(sfreq[s[left]] == tfreq[s[left]]){
                    matches--;
                }
                sfreq[s[left]]--;
                left ++;
            }
            right ++;
        }
        if(minLength == INT_MAX){
            return "";
        }
        return s.substr(start,minLength);
    }
};