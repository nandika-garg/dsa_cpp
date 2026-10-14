class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        stack <char> st;
        for (char c:s){
            if(c==')'){
                string x="";
                while(st.top()!='('){
                    x+=st.top();
                    st.pop();
                }
                st.pop();
                
                for(char y:x){
                    st.push(y);
                }

            }
            else {
                st.push(c);
            }
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
          reverse(result.begin(), result.end());
        return result;
    }
};