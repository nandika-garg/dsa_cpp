class Solution {
public:
    string minWindow(string s, string t) {
    int left=0;
    int right=0;
    unordered_map <char, int> mp1;
    unordered_map <char, int> mp2;
    int minlen=INT_MAX;
    int start=0;
    for (char c:t) mp1[c]++;
    int formed=0;
    while (right<s.size()){
        mp2[s[right]]++;
        if (mp1.count(s[right]) && mp2[s[right]]==mp1[s[right]]) formed++;
            while (formed==mp1.size()){
                if ((right-left+1)<minlen){
                    minlen=(right-left+1);
                    start=left;
                }
                mp2[s[left]]--;
                if (mp1.count(s[left]) && mp2[s[left]] < mp1[s[left]]) {
                    formed--;
                }
                left++;
            }
        
        right++;
    }
    if (minlen==INT_MAX) return "";
   return s.substr(start, minlen);
    }
};