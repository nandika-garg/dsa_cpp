class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;
    void backtrack(vector<int>& nums) {
        if (path.size()== nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;  
        if (i>0&&nums[i]==nums[i-1]&&used[i-1]) continue;

        path.push_back(nums[i]);
        used[i] = true;
        backtrack(nums);
        path.pop_back();
        used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);
        backtrack(nums);
        return result;  
    }
};