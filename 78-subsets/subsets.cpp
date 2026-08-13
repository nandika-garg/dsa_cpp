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

            backtrack(idx+1, nums);
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return result;
       
        
    }
};