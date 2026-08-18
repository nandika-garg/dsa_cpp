class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int maxnum=-1;
         if (nums.size()==k){
            for (int n:nums){
                maxnum=max(maxnum, n);
            }
            return maxnum;
        }
        unordered_map <int, int> mp;
        for (int n:nums) mp[n]++;
        if (k==1){
            for (auto& [key,val]: mp){
                if (val==1){
                    maxnum=max(maxnum, key);
                }
            }
            return maxnum;
        }
       
       if (mp[nums[0]]==1) maxnum=max(maxnum, nums[0]);
       if (mp[nums.back()]==1) maxnum=max(maxnum, nums.back());
       return maxnum;
        
    }
};