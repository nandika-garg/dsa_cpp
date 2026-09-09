class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> mp;

        for (int i = 0; i < wall.size(); i++) {
            long long prefix = 0;

            for (int j = 0; j < wall[i].size() - 1; j++) {
                prefix += wall[i][j];
                mp[prefix]++;
            }
        }
        int ans = 0;
        for (auto [pos, count] : mp) {
            ans = max(ans, count);
        }
        return wall.size() - ans;
    }
};