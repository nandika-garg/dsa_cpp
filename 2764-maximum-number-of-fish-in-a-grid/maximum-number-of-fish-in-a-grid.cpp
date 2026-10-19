class Solution {
public:
int dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int fish=grid[i][j];
        grid[i][j]=0;
        return (fish + dfs(i, j-1, grid) + dfs(i-1, j, grid) + dfs(i, j+1, grid) + dfs(i+1, j, grid));
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
        
    }
};