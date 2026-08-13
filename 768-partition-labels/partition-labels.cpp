class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        vector<int> lastOccurrence(26, 0);
        for (int i = 0; i < s.size(); i++) {
        lastOccurrence[s[i] - 'a'] = i;
        }
        int start=0;
        int end=0;
        for (int i=0; i<s.size(); i++){
            end=max(end, lastOccurrence[s[i]-'a']);
            if(i==end){
            result.push_back(end-start+1);
            start=i+1;
            end=i+1;
            }

        }
        return result;
        
    }
};