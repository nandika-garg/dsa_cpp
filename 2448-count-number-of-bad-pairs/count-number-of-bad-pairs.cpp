class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i] - i]++;
        }
        int maxValue = INT_MIN;
        long long goodpairs=0;
        for (auto it : mp) {
            long long freq=it.second;
            goodpairs+=(freq*(freq-1))/2;
        }
        long long totalpairs=(n*(n-1))/2;
        return totalpairs-goodpairs;
        
    }
};