class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(), nums.end());
        int min= nums[0];
        for (int n:nums){
            ans+=(n-min);
        }
        return ans;
    }
};