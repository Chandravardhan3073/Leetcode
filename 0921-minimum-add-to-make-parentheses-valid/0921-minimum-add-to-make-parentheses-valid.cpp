class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
                cnt--;
            }else{
                st.push(s[i]);//s[i] == '('
                cnt++;
            }
        }
        return cnt;
    }
};