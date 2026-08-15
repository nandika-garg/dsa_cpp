class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map <char, int> m1, m2;
        vector<int> result;
        for (char c: p){
            m1[c]++;
        }
        int left=0;
        int right=0;
        while (right<s.size()){
            m2[s[right]]++;
            if (right-left+1>p.size()){
                m2[s[left]]--;
                if (m2[s[left]]==0) m2.erase(s[left]);
                left++;
            }
            if (right-left+1==p.size()){
                if (m1==m2) result.push_back(left);
            }
            right++;
        }
        return result;
        
    }
};