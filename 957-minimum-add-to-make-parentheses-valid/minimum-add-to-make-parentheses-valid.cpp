class Solution {
public:
    int minAddToMakeValid(string s) {
        int moves=0;
        stack <char> st;
        for (char c:s){
            if (c==')'){
                if(!st.empty()&& st.top()=='(') st.pop();
                else moves++;
            }
            else st.push(c);
            } 
        
        while(!st.empty()){
            st.pop();
            moves++;
        }

        return moves;
    }
};