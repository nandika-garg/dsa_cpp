class Solution {
public:
    string removeStars(string s) {
        stack <int> st;
        for (char c: s){
            if (!st.empty() && c=='*') st.pop();
            if (c!='*') st.push(c);
        }
        string result="";
while (!st.empty()) {
    result += st.top();
    st.pop();
}
reverse(result.begin(), result.end());

        return result;
    }
};