class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(i);
        }
        for (int i = 0; i < edges.size(); i++) {
            s.erase(edges[i][1]);
        }
        if (s.size() != 1)
            return -1;
        int x = *s.begin();
        return x;
    }
};