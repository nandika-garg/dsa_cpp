class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int maxm=weights[0];
        int mincap=INT_MAX;
        int lowest = *max_element(weights.begin(), weights.end());
        int highest = accumulate(weights.begin(), weights.end(), 0);
        while (highest>=lowest){
            int mid=lowest+(highest-lowest)/2;
            int capacity=0;
            int currdays=1;
            for (int i:weights){
                capacity+=i;
                if (capacity>mid){
                    capacity=i;
                    currdays++;
                }
            }
            if (currdays>days){
                lowest=mid+1;
            }
            else {
                mincap=min(mincap, mid);
                highest=mid-1;
            }
        }
        return mincap;

    }
};