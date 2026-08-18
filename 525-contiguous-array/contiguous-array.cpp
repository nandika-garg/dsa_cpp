class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map <int , int> mp;
        mp[0]=-1;
        int sum=0;
        int maxlen=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==0) sum+=-1;
            else sum++;
            if (!mp.count(sum)) mp[sum]=i;
            if(mp.count(sum)){
                int len=i-mp[sum];
                maxlen=max (len,maxlen);
                
            }
        }
        return maxlen;

        
    }
};