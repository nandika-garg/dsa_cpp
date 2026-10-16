class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for (int i:nums) total+=i;
        int need= total-x;
        if (need==0) return nums.size();
        int left=0, sum=0, maxLen=0;
        for (int right=0; right<nums.size(); right++){
            sum+= nums[right];
             while (sum > need && left <= right) {
                sum -= nums[left];
                left++;
            }
            if (sum == need) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        if (maxLen==0) return -1;
        return nums.size()-maxLen;
        
    }
};