class Solution {
public:
    int distance(vector<int> p){
        return (p[0]*p[0]) + (p[1]*p[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
     priority_queue <pair<int,vector<int>>> pq;
     for (auto& point: points){
        pq.push({distance(point), point});
        if(pq.size()>k) pq.pop();
     }
        
        while (!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
     return result;


        
    }
};