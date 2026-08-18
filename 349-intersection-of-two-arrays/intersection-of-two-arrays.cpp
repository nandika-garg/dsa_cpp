class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> s;
        unordered_set <int> s2;
        vector <int> result;
        for (int n:nums1) s.insert(n);
        for (int n:nums2){

            if (!s2.count(n) && s.count(n)) {result.push_back(n);
            s2.insert(n);}
        }
        return result;
        
    }
};