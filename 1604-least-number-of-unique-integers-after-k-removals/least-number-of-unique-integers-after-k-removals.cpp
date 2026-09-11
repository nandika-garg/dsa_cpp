class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map <int, int> mp;
        for(int i:arr) mp[i]++;
        vector<int> freq;
        for(auto& i:mp) freq.push_back(i.second);
        sort(freq.begin(), freq.end());
        int ans=freq.size();
        for(int i:freq){
            if(k>=i){
                k-=i;
                ans--;
            }
            else break;
        }
        return ans;

        
    }
};