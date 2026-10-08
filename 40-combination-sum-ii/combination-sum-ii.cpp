class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(int idx, vector<int>& candidates, int target) {
        if(target==0){
            result.push_back(path);
            return;
        }
            if (target<0 || idx==candidates.size()) return;
        
            path.push_back(candidates[idx]);
            backtrack(idx+1, candidates, target-candidates[idx]);
            path.pop_back();
            int next=idx+1;
            while (next < candidates.size() && candidates[next] == candidates[idx]) next++;
            backtrack(next, candidates, target);  

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack (0, candidates, target);
        return result;
    }
};