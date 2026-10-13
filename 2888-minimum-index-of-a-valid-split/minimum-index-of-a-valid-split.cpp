class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        int dom;
        int domcount;
        for (int num : nums)
            mp[num]++;
        for (auto i : mp) {
            if (i.second > n / 2) {
                dom = i.first;
                domcount= i.second;
                break;
            }
        }
        int count=0;
        for (int i=0; i<n; i++){
            if (nums[i]==dom) count++;
            if(count>(i+1)/2 && (domcount-count)> (n-i-1)/2) return i;
        }
        return -1;
    }
};