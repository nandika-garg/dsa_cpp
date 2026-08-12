class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) freq[c - 'A']++;
        priority_queue<pair<int,int>> pq;
        for (int i=0; i<26; i++){
            if (freq[i]!=0) pq.push({freq[i], i});
        }
        int minlength= ((pq.top().first-1)*n)+pq.top().first;
        int highest= pq.top().first;
        pq.pop();
        
        while (!pq.empty() && highest==pq.top().first){
            minlength++;
            pq.pop();
        }
        minlength = max(minlength, (int)tasks.size());
        return minlength;
            
    }
};