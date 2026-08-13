class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for (char c:num) {
            while (!result.empty() && k>0 && result.back()>c){
                result.pop_back();
                k--;
            }
            result.push_back(c);   
        }
        while(k > 0) {
        result.pop_back();
        k--;
        }
        int i=0;
        while (i<result.size() && result[i]=='0') i++;
        result=result.substr(i);
        if (result.empty()) result='0';
        return result;
              
    }
};