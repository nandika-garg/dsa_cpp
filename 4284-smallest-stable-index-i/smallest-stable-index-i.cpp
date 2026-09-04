class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minpost(n);
        int maxval=INT_MIN;
        int minval=INT_MAX;
        
        for (int i=n-1; i>=0; i--){
            minval=min(nums[i], minval);
            minpost[i]=minval;
        }
        for(int i=0; i<n; i++){
            maxval=max(nums[i], maxval);
            if (maxval-minpost[i]<=k) return i;
        }
        return -1;

        
    }
};