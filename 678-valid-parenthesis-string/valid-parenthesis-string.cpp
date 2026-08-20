class Solution {
public:
    bool checkValidString(string s) {
        int high=0;
        int low=0;
        for (char c:s){
            if (c=='('){
                high++;
                low++;
            }
            else if (c==')'){
                high--;
                low--;
                low=max(0,low);
            }
            else {
                high++;
                low--;
                low=max(0,low);
            }
            if (high<0) return false;
        }
        return low==0;
    }
};