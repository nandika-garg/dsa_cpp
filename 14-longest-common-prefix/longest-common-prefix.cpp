class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        for (int j=0; j<strs[0].size(); j++){
    for (int i=0; i<strs.size(); i++){
        if (strs[i][j]!=strs[0][j]) return result;
    }
    result+=strs[0][j];
}    
return result;    
    }
};