class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int removed=0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
         return a[1] < b[1];
        });
        int time=intervals[0][0];
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0]>=time) time=intervals[i][1];
            else removed++;

        }return removed;
    }
};