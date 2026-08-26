class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack (int idx, vector<int>& candidates, int target){
        if (target==0){
            result.push_back(path);
            return;
        }
        if (target<0 || idx==candidates.size()) return;
        
            path.push_back(candidates[idx]);
            backtrack(idx, candidates, target-candidates[idx]);
            path.pop_back();
            backtrack(idx+1, candidates, target);
            
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack (0, candidates, target);
        return result;
    }
};