class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a'|| ch =='e'||ch =='i'||ch =='o'|| ch=='u'){
            return true;
        }else{
            return false;
        }
    }
    int maxVowels(string s, int k) {
        int n = s.size(),r=0;
        int maxVowel = 0;
        int cnt = 0;
        int l = 0;
        while(r<k){
            if(isVowel(s[r])){
                cnt++;
            }
            r++;
        }
        maxVowel = max(maxVowel,cnt);
        cout << r << " ";
        while(r <s.size()){
            if(isVowel(s[l])){
                cnt--;
            }
            l++;
            if(isVowel(s[r])){
                cnt++;
            }
            r++;
            maxVowel = max(cnt,maxVowel);
        }
        return maxVowel;
    }
};