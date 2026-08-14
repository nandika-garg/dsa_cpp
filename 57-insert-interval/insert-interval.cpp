class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool inserted=false;
        int start=newInterval[0],end= newInterval[1];
        for (int i=0; i<intervals.size(); i++){
            if (newInterval[0]>intervals[i][1]) result.push_back(intervals[i]);
            else if (newInterval[1]<intervals[i][0]){
                if (!inserted) {
                    result.push_back ({start,end});
                    inserted=true;
                    }
                result.push_back(intervals[i]);               
            }
            else{
                if (newInterval[0]>intervals[i][0]) start=intervals[i][0];
                if (newInterval[1]<intervals[i][1]) end=intervals[i][1];
            }
        }
        if (!inserted) result.push_back ({start,end});
        return result;
        
    }
};