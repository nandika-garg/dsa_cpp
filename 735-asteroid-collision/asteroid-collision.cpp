class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for (int i:asteroids){
            if(!st.empty() && st.top()>0 && i<0){
                if (st.top()>-i) continue;
                else if (st.top()==-i) {st.pop(); continue;}
                else{
                while (!st.empty() && st.top()<-i && st.top()>0) st.pop();
                if (st.empty()|| st.top()<0) st.push(i);
                else if (st.top() == -i)
                st.pop();
                }              
            }
            else st.push(i);
        }
        vector<int> result;
        while (!st. empty()) {
             result.push_back(st.top()); st.pop(); 
             }
        reverse(result.begin(), result.end());
        return result;
        
    }
};