class Solution {
public:
    string reorganizeString(string s) {
        unordered_map <char, int> mp;
        priority_queue <pair<int,char>> pq;
        string result;
        for (char c: s) mp[c]++;
        for (auto & [key, val]:mp){
            pq.push({val,key});
        }
        if (pq.top().first > (s.size()+1)/2) return "";
        while (!pq.empty()){
            auto [freq1, val1] = pq.top();
            pq.pop();
            result+=val1;
            freq1--;
            if (!pq.empty()){
            auto [freq2, val2] = pq.top();
            pq.pop();
            result+=val2;
            freq2--;   
            if (freq2 > 0) pq.push({freq2, val2});   
            }              
            if (freq1 > 0) pq.push({freq1, val1});
            
        }
        return result;    
    }
};