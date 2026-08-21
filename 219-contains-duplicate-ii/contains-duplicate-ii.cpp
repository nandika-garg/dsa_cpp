class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left=0;
        int right=k;
        unordered_map <int, int> mp;
        for (int i=0; i<nums.size(); i++){
            if (mp.count(nums[i])) return true;
            mp[nums[i]]++;
            if(i==right){
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                right++;
                left++;
            } 
        } 
        return false; 
    }
};