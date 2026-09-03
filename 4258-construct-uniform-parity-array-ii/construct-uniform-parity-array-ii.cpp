class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int minm=INT_MAX;
        int even=0;
        int odd=0;
        for(int n:nums1){
            minm=min(minm, n);
            if (n%2==0) even++;
            else odd++;
        }
        if (even==n || odd==n) return true;
        return (minm%2!=0);
    }
};