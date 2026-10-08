class Solution {
public:
vector<vector<int>> result;
     vector<int> path; 
        void backtrack(int idx, vector<int>& nums ){
            if (idx==nums.size()){
                result.push_back(path);
                return;
            }
            path.push_back(nums[idx]);
            backtrack(idx+1, nums);
            path.pop_back();
            int next=idx+1;
            while (next<nums.size()&&nums[next]==nums[idx]) next++;
            backtrack(next, nums);
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return result;

        
    }
};