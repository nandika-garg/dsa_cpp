class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int open=0;
        int close=0;
        stack<char> st;
        for (char c : s){
            if (c=='(') open++;
            else close++;
            if(!st.empty()&&open==close){
                string path="";
                while (!st.empty()){
                path.push_back(st.top());
                st.pop();
                }
                path.pop_back();
                reverse(path.begin(), path.end());
                result+=path;
            }
            else st.push(c);
        }
        return result;
        
    }
};