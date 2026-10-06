class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] =='('){
                st.push(s[i]);
                cnt++;
            }else{//s[i] == ')'
                if(!st.empty()){
                    st.pop();
                    cnt--;
                }else{//no stack element '('
                    cnt++;
                }
            }
        }
        return cnt;
    }
};