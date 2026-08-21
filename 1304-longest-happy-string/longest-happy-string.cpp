class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s;
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        while (pq.top().first!=0 ){
            if (s.size()>=2 && s[s.size()-1]==pq.top().second && s[s.size()-2]==pq.top().second){
                pair<int,char> store=pq.top();
                pq.pop();
                if (pq.top().first==0) return s;
                else{
                    pair<int,char> added=pq.top();
                    pq.pop();
                    s+=added.second;
                    added.first--;
                    pq.push(added);
                    pq.push(store);
                }
            }
             pair<int,char> added=pq.top();
                    pq.pop();
                    s+=added.second;
                    added.first--;
                    pq.push(added);
        }
        return s;  
    }
};