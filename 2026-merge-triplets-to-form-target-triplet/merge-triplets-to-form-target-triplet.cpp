class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool hit0 = false, hit1 = false, hit2 = false;
        for (auto& t: triplets){
            if (t[0]<=target[0] && t[1]<=target[1] && t[2]<=target[2]){
                if(t[0]==target[0]) hit0=true;
                if(t[1]==target[1]) hit1=true;
                if(t[2]==target[2]) hit2=true;
            }
        }
        return hit0 && hit1 && hit2;
        
    }
};