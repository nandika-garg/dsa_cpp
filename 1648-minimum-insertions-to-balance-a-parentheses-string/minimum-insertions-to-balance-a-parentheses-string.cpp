class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
       int open=0;
       int close=0;
       int n=s.size();
       for (int i=0; i<n; i++){
        if (s[i]=='('){
            if(close%2!=0){
                ans++;
                close++;
            }
            open+=2;
        }
        else close++;
        if(close>open){
            ans+=1;
            open+=2;
        }
       }
       if(open>close){
        ans+=open-close;
       }
       return ans;
        
    }
};