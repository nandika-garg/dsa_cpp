class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum=0;
        int highest=piles[0];
        for (int i=0; i<piles.size(); i++){
            sum+=piles[i];
            highest=max(piles[i], highest);
        }
        int lowest=(sum+h-1)/h;
        int mintime=highest;
    while (lowest <= highest) {
            int mid = lowest + (highest - lowest) / 2;
            int count=0;
            for (int pile:piles){
                    count+=(pile+mid-1)/mid;
            }
            if (count<=h) {
                mintime=min(mid, mintime);
                highest=mid-1;
                } 
            else lowest=mid+1;
        }
        return mintime;
    }
};
