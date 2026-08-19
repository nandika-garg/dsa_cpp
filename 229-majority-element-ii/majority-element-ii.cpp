class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        unordered_map <int, int> mp;
        for (int i:nums) {mp[i]++;
        if (mp[i]==(n/3)+1) result.push_back(i);
        }
     
        return result;
    }
};