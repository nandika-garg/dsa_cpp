class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) > abs(b); });
        int half=ceil((double)nums.size()/2);
        long long sum=0;
        for(int i=0; i<half; i++){
            sum+=nums[i]* nums[i];
        }
        for (int i=half; i<nums.size(); i++){
            sum-=nums[i]*nums[i];
        }
        return sum;
    }
};