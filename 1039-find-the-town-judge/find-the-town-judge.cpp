class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        unordered_map <int, int> mp;
        for (int i=0; i<trust.size(); i++) mp[trust[i][1]]++;
        for (int i=0; i<trust.size(); i++){
            mp.erase(trust[i][0]);
        }
        for(auto& [key,val]:mp){
            if(val==n-1) return key;
        }
        return -1;
    }
};